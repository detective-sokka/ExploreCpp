template <typename T>
class ConditionVariable {

    public:
        ConditionVariable() {            
        }

        void setValue(T val) {            
            {
                std::lock_guard<std::mutex> l(mMtx);
                mValue = val;
            }
            mCv.notify_one();
        }

        T getValue () {
            std::unique_lock<std::mutex> l(mMtx);
            mCv.wait(l, [this] () {
                return mValue.has_value(); 
            });
            return *mValue;
        }

    private:
        std::optional<T> mValue;
        std::mutex mMtx;
        std::condition_variable mCv;
};