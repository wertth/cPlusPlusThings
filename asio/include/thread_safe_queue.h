#ifndef CPLUSPLUSTHINGS_THREAD_SAFE_QUEUE_H
#define CPLUSPLUSTHINGS_THREAD_SAFE_QUEUE_H

#include <deque>
#include <mutex>
#include <optional>

template <class T>
class ThreadSafeQueue {
protected:
    std::deque<T> m_queue;
    mutable std::mutex m_mutex;

public:
    ThreadSafeQueue() = default;
    ThreadSafeQueue(const ThreadSafeQueue<T>&) = delete;
    virtual ~ThreadSafeQueue() {clear();}
    const T& front() const {
        std::scoped_lock lock(m_mutex);
            return m_queue.front();
    }

    const T& back() const {
        std::scoped_lock lock(m_mutex);
        return m_queue.back();

    }

    void push_back(const T& val) {
        std::scoped_lock lock(m_mutex);
        m_queue.emplace_back(std::move(val));
    }

    void push_front(const T& val) {
        std::scoped_lock lock(m_mutex);
        m_queue.emplace_front(std::move(val));
    }

    T pop_back() {
        std::scoped_lock lock(m_mutex);
        T val = std::move(m_queue.back());
        m_queue.pop_back();
        return val;
    }

    T pop_front() {
        std::scoped_lock lock(m_mutex);
        T val = std::move(m_queue.front());//!!!
        m_queue.pop_front();
        return val;
    }
    size_t size() const {
        std::scoped_lock lock(m_mutex);
        return m_queue.size();
    }

    void clear() {
        std::scoped_lock lock(m_mutex);
        m_queue.clear();
    }
    bool empty() const {
        std::scoped_lock lock(m_mutex);
        return m_queue.empty();
    }
};

#endif //CPLUSPLUSTHINGS_THREAD_SAFE_QUEUE_H
