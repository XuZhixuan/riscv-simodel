#pragma once

#include <array>

#include "common/common.hh"
#include "SimObject.hh"

namespace Sim
{
    /**
     * @brief Data structure class, containing data, limited access
     * @tparam T
     */
    template<typename T>
    class LoopQueue : public SimObject
    {
    protected:
        // Storing data
        std::vector<T> m_data;

        // Head of loop queue
        size_t m_head = 0;

        // Tail of loop queue
        size_t m_tail = 0;

        // Used element count
        size_t m_used = 0;

    public:
        /**
         * @brief Construct a new loop queue with given size
         * @param name
         * @param size
         */
        LoopQueue(const std::string &name, size_t size)
                : SimObject(name)
        {
            m_data.resize(size);
        }

        /**
         * @brief default deconstruct func
         */
        ~LoopQueue() override = default;

        /**
         * @brief Get head of the loop queue
         * @return
         */
        inline size_t get_head()
        {
            return m_head;
        }

        /**
         * @brief Get tail of the loop queue
         * @return
         */
        inline size_t get_tail()
        {
            return m_tail;
        }

        /**
         * @brief Get max size of loop queue
         * @return
         */
        inline size_t get_size()
        {
            return m_data.size();
        }

        /**
         * @brief Get used count of loop queue
         * @return
         */
        inline size_t get_used()
        {
            return m_used;
        }

        /**
         * @brief Get if this queue is full
         * @return
         */
        inline bool full()
        {
            return m_used == get_size();
        }

        /**
         * @brief Get if this queue is empty
         * @return
         */
        inline bool empty()
        {
            return m_used == 0;
        }

        /**
         * @brief Get the first element in the queue
         * @return
         */
        T &front()
        {
            do_assert(!empty(), "Attempting to get head element when queue is empty.");
            return m_data[m_head];
        }

        /**
         * @brief Get the last element in the queue
         * @return
         */
        T &end()
        {
            do_assert(!empty(), "Attempting to get tail element when queue is empty.");
            return m_data[m_tail];
        }

        /**
         * @brief Push a new element into the queue
         * @param data
         * @return idx: index to last pushed element
         */
        size_t push(const T &data)
        {
            do_assert(!full(), "Attempting to push when queue is full.");
            m_data[m_tail] = data;

            size_t idx = m_tail;

            if (m_tail == get_size() - 1)
            {
                m_tail = 0;
            }
            else
            {
                m_tail++;
            }
            m_used++;
            return idx;
        }

        /**
         * @brief Pop the first element from the queue
         * @return
         */
        T &pop()
        {
            do_assert(!empty(), "Attempting to pop when queue is empty.");
            T data = m_data[m_head];
            if (m_head == get_size() - 1)
            {
                m_head = 0;
            }
            else
            {
                m_head++;
            }
            m_used--;
            return data;
        }

        /**
         * @brief Rollback the latest push action
         */
        void rollback()
        {
            do_assert(!empty(), "Attempting to rollback when queue is empty.");
            if (m_tail == 0)
            {
                m_tail = get_size() - 1;
            }
            else
            {
                m_tail--;
            }
            m_used--;
        }

        /**
         * @brief Reset the loop queue: clear elements
         */
        void reset() override
        {
            m_tail = m_head = m_used = 0;

        }

        /**
         * @brief SimObject interface funcs, not implemented.
         */
        void tick() override
        {}

        /**
         * @brief SimObject interface funcs, not implemented.
         */
        void advance() override
        {}

        /**
         * @brief SimObject interface funcs, not implemented.
         */
        void evaluate() override
        {}
    };

} // Sim
