#ifndef PATOMIC_TEST_ID_PARAM_HPP
#define PATOMIC_TEST_ID_PARAM_HPP

#include <array>
#include <cstdlib>
#include <random>
#include <type_traits>
#include <vector>

#include <patomic/types/ids.h>
#include <patomic/types/memory_order.h>
#include <gtest/gtest.h>


namespace patomic {
    namespace test {

        template <size_t N> using order_array = std::array<patomic_memory_order_t, N>;
        template <size_t N> using id_array = std::array<patomic_id_t, N>;

        static constexpr auto get_ids() -> id_array<5>
        {
            return {
                patomic_id_NULL
                ,patomic_id_MSVC
                ,patomic_id_STD
                ,patomic_id_TSX
                ,patomic_id_GNU
            };
        }

        static constexpr auto get_id_name(patomic_id_t id) -> const char*
        {
            switch (id)
            {
                case patomic_id_NULL: return "NULL";
                case patomic_id_MSVC: return "MSVC";
                case patomic_id_STD: return "STD";
                case patomic_id_TSX: return "TSX";
                case patomic_id_GNU: return "GNU";
                default: return "UNKNOWN";
            }
        }

        static constexpr auto get_orders() -> order_array<6>
        {
            return {
                    patomic_RELAXED,
                    patomic_CONSUME,
                    patomic_ACQUIRE,
                    patomic_RELEASE,
                    patomic_ACQ_REL,
                    patomic_SEQ_CST
            };
        }

        static constexpr auto get_order_name(patomic_memory_order_t order) -> const char*
        {
            switch (order)
            {
                case patomic_RELAXED: return "RELAXED";
                case patomic_CONSUME: return "CONSUME";
                case patomic_ACQUIRE: return "ACQUIRE";
                case patomic_RELEASE: return "RELEASE";
                case patomic_ACQ_REL: return "ACQ_REL";
                case patomic_SEQ_CST: return "SEQ_CST";
                default: return "UNKNOWN";
            }
        }

        static auto get_widths() -> std::vector<size_t>
        {
            // widths in bytes
            static const auto widths = std::vector<size_t>{
                    1, 2, 4, 8, 16
            };
            return widths;
        }

        struct sized_param
        {
            size_t width;
            patomic_memory_order_t order;
            patomic_id_t id;
            unsigned int seed;
            bool is_explicit;
            bool is_signed;
        };

}}  // ns patomic::test


#endif  // !PATOMIC_TEST_ID_PARAM_HPP
