// gmock_optional.cpp : Defines the entry point for the application.
//

#include "gmock_optional.h"

using namespace std;

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <boost/optional/optional.hpp>

class SomeClass
{

};

class Tester
{
public:
    virtual void Foo(boost::optional<SomeClass&> const& val) = 0;
    virtual ~Tester() = default;
};

class MockTester : public Tester
{
public:

    MOCK_METHOD(
        void, Foo,
        (boost::optional<SomeClass&> const& val), (override));
};

void Function(Tester& tester)
{
    tester.Foo({});
}

TEST(TesterTest, CheckOptional) {
    MockTester mock;
    EXPECT_CALL(mock, Foo).Times(1);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
