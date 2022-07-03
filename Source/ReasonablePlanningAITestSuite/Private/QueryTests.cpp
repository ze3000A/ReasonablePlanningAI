#include "Misc/AutomationTest.h"
#include "ReasonablePlanningAITestTypes.h"
#include "Composer/Queries/StateQuery_CompareToBool.h"
#include "Composer/Queries/StateQuery_CompareToFloat.h"
#include "Composer/Queries/StateQuery_CompareToInteger.h"
#include "Composer/Queries/StateQuery_CompareToStateValue.h"
#include "States/State_Map.h"

BEGIN_DEFINE_SPEC(ReasonablePlanningQueryCompareToBoolSpec, "ReasonablePlanningAI.Queries.CompareBool", EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
	UStateQuery_CompareToBool* ClassUnderTest;
	UTestPlanningState* GivenState;
END_DEFINE_SPEC(ReasonablePlanningQueryCompareToBoolSpec)
void ReasonablePlanningQueryCompareToBoolSpec::Define()
{
	BeforeEach([this]()
		{
			ClassUnderTest = NewObject<UStateQuery_CompareToBool>();
			GivenState = NewObject<UTestPlanningState>();

			ClassUnderTest->SetQueriedState(UTestPlanningState::NAME_TheBoolValue, EStatePropertyType::Bool);
		});

	Describe("Successful queries", [this]()
		{
			It("Should return success when the value defined is less than state value", [this]()
				{
					ClassUnderTest->SetComparisonOperation(EStateQueryCompareToOperation::LessThan);

					GivenState->SetBool(UTestPlanningState::NAME_TheBoolValue, false);
					ClassUnderTest->SetComparisonValue(true);
					TestEqual("UStateQuery_CompareToBool::Query", ClassUnderTest->Query(GivenState), EStateQueryResult::Succeeded);
				});

			It("Should return success when the value defined is less than or equal to state value", [this]()
				{
					ClassUnderTest->SetComparisonOperation(EStateQueryCompareToOperation::LessThanOrEqualTo);

					GivenState->SetBool(UTestPlanningState::NAME_TheBoolValue, false);
					ClassUnderTest->SetComparisonValue(true);
					TestEqual("UStateQuery_CompareToBool::Query", ClassUnderTest->Query(GivenState), EStateQueryResult::Succeeded);

					ClassUnderTest->SetComparisonValue(false);
					TestEqual("UStateQuery_CompareToBool::Query", ClassUnderTest->Query(GivenState), EStateQueryResult::Succeeded);
				});

			It("Should return success when the value defined is greater than state value", [this]()
				{
					ClassUnderTest->SetComparisonOperation(EStateQueryCompareToOperation::GreaterThan);

					GivenState->SetBool(UTestPlanningState::NAME_TheBoolValue, true);
					ClassUnderTest->SetComparisonValue(false);
					TestEqual("UStateQuery_CompareToBool::Query", ClassUnderTest->Query(GivenState), EStateQueryResult::Succeeded);
				});

			It("Should return success when the value defined is greater than or equal to state value", [this]()
				{
					ClassUnderTest->SetComparisonOperation(EStateQueryCompareToOperation::GreaterThanOrEqualTo);

					GivenState->SetBool(UTestPlanningState::NAME_TheBoolValue, true);
					ClassUnderTest->SetComparisonValue(true);
					TestEqual("UStateQuery_CompareToBool::Query", ClassUnderTest->Query(GivenState), EStateQueryResult::Succeeded);

					ClassUnderTest->SetComparisonValue(false);
					TestEqual("UStateQuery_CompareToBool::Query", ClassUnderTest->Query(GivenState), EStateQueryResult::Succeeded);
				});

			It("Should return success when the value defined is equal to the value", [this]()
				{
					ClassUnderTest->SetComparisonOperation(EStateQueryCompareToOperation::EqualTo);

					GivenState->SetBool(UTestPlanningState::NAME_TheBoolValue, true);
					ClassUnderTest->SetComparisonValue(true);
					TestEqual("UStateQuery_CompareToBool::Query", ClassUnderTest->Query(GivenState), EStateQueryResult::Succeeded);
				});

			It("Should return success when the value defined is not equal to the value", [this]()
				{
					ClassUnderTest->SetComparisonOperation(EStateQueryCompareToOperation::NotEqualTo);

					GivenState->SetBool(UTestPlanningState::NAME_TheBoolValue, false);
					ClassUnderTest->SetComparisonValue(true);
					TestEqual("UStateQuery_CompareToBool::Query", ClassUnderTest->Query(GivenState), EStateQueryResult::Succeeded);

					GivenState->SetBool(UTestPlanningState::NAME_TheBoolValue, true);
					ClassUnderTest->SetComparisonValue(false);
					TestEqual("UStateQuery_CompareToBool::Query", ClassUnderTest->Query(GivenState), EStateQueryResult::Succeeded);
				});
		});

	AfterEach([this]()
		{
			ClassUnderTest->ConditionalBeginDestroy();
			GivenState->ConditionalBeginDestroy();
		});
}

BEGIN_DEFINE_SPEC(ReasonablePlanningQueryCompareToFloatSpec, "ReasonablePlanningAI.Queries.CompareFloat", EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
	UStateQuery_CompareToFloat* ClassUnderTest;
	UTestPlanningState* GivenState;
END_DEFINE_SPEC(ReasonablePlanningQueryCompareToFloatSpec)
void ReasonablePlanningQueryCompareToFloatSpec::Define()
{
	BeforeEach([this]()
		{
			ClassUnderTest = NewObject<UStateQuery_CompareToFloat>();
			GivenState = NewObject<UTestPlanningState>();

			ClassUnderTest->SetQueriedState(UTestPlanningState::NAME_TheFloatValue, EStatePropertyType::Float);
		});

	Describe("Successful queries", [this]()
		{
			It("Should return success when the value defined is less than state value", [this]()
				{
					ClassUnderTest->SetComparisonOperation(EStateQueryCompareToOperation::LessThan);

					GivenState->SetFloat(UTestPlanningState::NAME_TheFloatValue, 100.0f);
					ClassUnderTest->SetComparisonValue(150.f);
					TestEqual("UStateQuery_CompareToFloat::Query", ClassUnderTest->Query(GivenState), EStateQueryResult::Succeeded);
				});

			It("Should return success when the value defined is less than or equal to state value", [this]()
				{
					ClassUnderTest->SetComparisonOperation(EStateQueryCompareToOperation::LessThanOrEqualTo);

					GivenState->SetFloat(UTestPlanningState::NAME_TheFloatValue, -25.f);
					ClassUnderTest->SetComparisonValue(100.f);
					TestEqual("UStateQuery_CompareToFloat::Query", ClassUnderTest->Query(GivenState), EStateQueryResult::Succeeded);

					ClassUnderTest->SetComparisonValue(-25.f);
					TestEqual("UStateQuery_CompareToFloat::Query", ClassUnderTest->Query(GivenState), EStateQueryResult::Succeeded);
				});

			It("Should return success when the value defined is greater than state value", [this]()
				{
					ClassUnderTest->SetComparisonOperation(EStateQueryCompareToOperation::GreaterThan);

					GivenState->SetFloat(UTestPlanningState::NAME_TheFloatValue, -2500.f);
					ClassUnderTest->SetComparisonValue(-100000000.f);
					TestEqual("UStateQuery_CompareToFloat::Query", ClassUnderTest->Query(GivenState), EStateQueryResult::Succeeded);
				});

			It("Should return success when the value defined is greater than or equal to state value", [this]()
				{
					ClassUnderTest->SetComparisonOperation(EStateQueryCompareToOperation::GreaterThanOrEqualTo);

					GivenState->SetFloat(UTestPlanningState::NAME_TheFloatValue, 1.f);
					ClassUnderTest->SetComparisonValue(0.56f);
					TestEqual("UStateQuery_CompareToFloat::Query", ClassUnderTest->Query(GivenState), EStateQueryResult::Succeeded);

					ClassUnderTest->SetComparisonValue(1.f);
					TestEqual("UStateQuery_CompareToFloat::Query", ClassUnderTest->Query(GivenState), EStateQueryResult::Succeeded);
				});

			It("Should return success when the value defined is equal to the value", [this]()
				{
					ClassUnderTest->SetComparisonOperation(EStateQueryCompareToOperation::EqualTo);

					GivenState->SetFloat(UTestPlanningState::NAME_TheFloatValue, 456.789f);
					ClassUnderTest->SetComparisonValue(456.789f);
					TestEqual("UStateQuery_CompareToFloat::Query", ClassUnderTest->Query(GivenState), EStateQueryResult::Succeeded);
				});

			It("Should return success when the value defined is not equal to the value", [this]()
				{
					ClassUnderTest->SetComparisonOperation(EStateQueryCompareToOperation::NotEqualTo);

					GivenState->SetFloat(UTestPlanningState::NAME_TheFloatValue, -456.789f);
					ClassUnderTest->SetComparisonValue(456.789f);
					TestEqual("UStateQuery_CompareToFloat::Query", ClassUnderTest->Query(GivenState), EStateQueryResult::Succeeded);

					GivenState->SetFloat(UTestPlanningState::NAME_TheFloatValue, 456.789f);
					ClassUnderTest->SetComparisonValue(-456.789f);
					TestEqual("UStateQuery_CompareToFloat::Query", ClassUnderTest->Query(GivenState), EStateQueryResult::Succeeded);
				});
		});

	AfterEach([this]()
		{
			ClassUnderTest->ConditionalBeginDestroy();
			GivenState->ConditionalBeginDestroy();
		});
}

BEGIN_DEFINE_SPEC(ReasonablePlanningQueryCompareToIntegerSpec, "ReasonablePlanningAI.Queries.CompareInteger", EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
	UStateQuery_CompareToInteger* ClassUnderTest;
	UTestPlanningState* GivenState;
END_DEFINE_SPEC(ReasonablePlanningQueryCompareToIntegerSpec)
void ReasonablePlanningQueryCompareToIntegerSpec::Define()
{
	BeforeEach([this]()
		{
			ClassUnderTest = NewObject<UStateQuery_CompareToInteger>();
			GivenState = NewObject<UTestPlanningState>();

			ClassUnderTest->SetQueriedState(UTestPlanningState::NAME_TheIntValue, EStatePropertyType::Int);
		});

	Describe("Successful queries", [this]()
		{
			It("Should return success when the value defined is less than state value", [this]()
				{
					ClassUnderTest->SetComparisonOperation(EStateQueryCompareToOperation::LessThan);

					GivenState->SetInt(UTestPlanningState::NAME_TheIntValue, 10);
					ClassUnderTest->SetComparisonValue(15);
					TestEqual("UStateQuery_CompareToInteger::Query", ClassUnderTest->Query(GivenState), EStateQueryResult::Succeeded);
				});

			It("Should return success when the value defined is less than or equal to state value", [this]()
				{
					ClassUnderTest->SetComparisonOperation(EStateQueryCompareToOperation::LessThanOrEqualTo);

					GivenState->SetInt(UTestPlanningState::NAME_TheIntValue, 45);
					ClassUnderTest->SetComparisonValue(800);
					TestEqual("UStateQuery_CompareToInteger::Query", ClassUnderTest->Query(GivenState), EStateQueryResult::Succeeded);

					ClassUnderTest->SetComparisonValue(45);
					TestEqual("UStateQuery_CompareToInteger::Query", ClassUnderTest->Query(GivenState), EStateQueryResult::Succeeded);
				});

			It("Should return success when the value defined is greater than state value", [this]()
				{
					ClassUnderTest->SetComparisonOperation(EStateQueryCompareToOperation::GreaterThan);

					GivenState->SetInt(UTestPlanningState::NAME_TheIntValue, 600);
					ClassUnderTest->SetComparisonValue(-1);
					TestEqual("UStateQuery_CompareToInteger::Query", ClassUnderTest->Query(GivenState), EStateQueryResult::Succeeded);
				});

			It("Should return success when the value defined is greater than or equal to state value", [this]()
				{
					ClassUnderTest->SetComparisonOperation(EStateQueryCompareToOperation::GreaterThanOrEqualTo);

					GivenState->SetInt(UTestPlanningState::NAME_TheIntValue, 100);
					ClassUnderTest->SetComparisonValue(50);
					TestEqual("UStateQuery_CompareToInteger::Query", ClassUnderTest->Query(GivenState), EStateQueryResult::Succeeded);

					ClassUnderTest->SetComparisonValue(100);
					TestEqual("UStateQuery_CompareToInteger::Query", ClassUnderTest->Query(GivenState), EStateQueryResult::Succeeded);
				});

			It("Should return success when the value defined is equal to the value", [this]()
				{
					ClassUnderTest->SetComparisonOperation(EStateQueryCompareToOperation::EqualTo);

					GivenState->SetInt(UTestPlanningState::NAME_TheIntValue, 60);
					ClassUnderTest->SetComparisonValue(60);
					TestEqual("UStateQuery_CompareToInteger::Query", ClassUnderTest->Query(GivenState), EStateQueryResult::Succeeded);
				});

			It("Should return success when the value defined is not equal to the value", [this]()
				{
					ClassUnderTest->SetComparisonOperation(EStateQueryCompareToOperation::NotEqualTo);

					GivenState->SetInt(UTestPlanningState::NAME_TheIntValue, 20);
					ClassUnderTest->SetComparisonValue(56789);
					TestEqual("UStateQuery_CompareToInteger::Query", ClassUnderTest->Query(GivenState), EStateQueryResult::Succeeded);

					GivenState->SetInt(UTestPlanningState::NAME_TheIntValue, -20);
					ClassUnderTest->SetComparisonValue(20);
					TestEqual("UStateQuery_CompareToInteger::Query", ClassUnderTest->Query(GivenState), EStateQueryResult::Succeeded);
				});
		});

	AfterEach([this]()
		{
			ClassUnderTest->ConditionalBeginDestroy();
			GivenState->ConditionalBeginDestroy();
		});
}

BEGIN_DEFINE_SPEC(ReasonablePlanningQueryCompareToStateSpec, "ReasonablePlanningAI.Queries.CompareState", EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
	UStateQuery_CompareToStateValue* ClassUnderTest;
	UState_Map* GivenState;
END_DEFINE_SPEC(ReasonablePlanningQueryCompareToStateSpec)
void ReasonablePlanningQueryCompareToStateSpec::Define()
{
	BeforeEach([this]()
		{
			ClassUnderTest = NewObject<UStateQuery_CompareToStateValue>();
			GivenState = NewObject<UState_Map>();
			GivenState->SetAsDynamic(true);
		});

	Describe("Successful queries for Integer", [this]()
		{
			It("Should return success when the value defined is less than state value", [this]()
				{
					ClassUnderTest->SetComparisonOperation(EStateQueryCompareToOperation::LessThan);
					ClassUnderTest->SetQueriedState("A", EStatePropertyType::Int);
					ClassUnderTest->SetComparedToState("B", EStatePropertyType::Int);

					GivenState->SetInt("A", 10);
					GivenState->SetInt("B", 20);
					TestEqual("UStateQuery_CompareToStateValue::Query", ClassUnderTest->Query(GivenState), EStateQueryResult::Succeeded);
				});

			It("Should return success when the value defined is less than or equal to state value", [this]()
				{
					ClassUnderTest->SetComparisonOperation(EStateQueryCompareToOperation::LessThanOrEqualTo);
					ClassUnderTest->SetQueriedState("A", EStatePropertyType::Int);
					ClassUnderTest->SetComparedToState("B", EStatePropertyType::Int);

					GivenState->SetInt("A", 10);
					GivenState->SetInt("B", 20);
					TestEqual("UStateQuery_CompareToStateValue::Query", ClassUnderTest->Query(GivenState), EStateQueryResult::Succeeded);

					GivenState->SetInt("B", 10);
					TestEqual("UStateQuery_CompareToStateValue::Query", ClassUnderTest->Query(GivenState), EStateQueryResult::Succeeded);
				});

			It("Should return success when the value defined is greater than state value", [this]()
				{
					ClassUnderTest->SetComparisonOperation(EStateQueryCompareToOperation::GreaterThan);
					ClassUnderTest->SetQueriedState("A", EStatePropertyType::Int);
					ClassUnderTest->SetComparedToState("B", EStatePropertyType::Int);

					GivenState->SetInt("A", 30);
					GivenState->SetInt("B", 10);
					TestEqual("UStateQuery_CompareToStateValue::Query", ClassUnderTest->Query(GivenState), EStateQueryResult::Succeeded);
				});

			It("Should return success when the value defined is greater than or equal to state value", [this]()
				{
					ClassUnderTest->SetComparisonOperation(EStateQueryCompareToOperation::GreaterThanOrEqualTo);
					ClassUnderTest->SetQueriedState("A", EStatePropertyType::Int);
					ClassUnderTest->SetComparedToState("B", EStatePropertyType::Int);

					GivenState->SetInt("A", 30);
					GivenState->SetInt("B", 29);
					TestEqual("UStateQuery_CompareToStateValue::Query", ClassUnderTest->Query(GivenState), EStateQueryResult::Succeeded);

					GivenState->SetInt("B", 30);
					TestEqual("UStateQuery_CompareToStateValue::Query", ClassUnderTest->Query(GivenState), EStateQueryResult::Succeeded);
				});

			It("Should return success when the value defined is equal to the value", [this]()
				{
					ClassUnderTest->SetComparisonOperation(EStateQueryCompareToOperation::EqualTo);
					ClassUnderTest->SetQueriedState("A", EStatePropertyType::Int);
					ClassUnderTest->SetComparedToState("B", EStatePropertyType::Int);

					GivenState->SetInt("A", 400000);
					GivenState->SetInt("B", 400000);
					TestEqual("UStateQuery_CompareToStateValue::Query", ClassUnderTest->Query(GivenState), EStateQueryResult::Succeeded);
				});

			It("Should return success when the value defined is not equal to the value", [this]()
				{
					ClassUnderTest->SetComparisonOperation(EStateQueryCompareToOperation::NotEqualTo);
					ClassUnderTest->SetQueriedState("A", EStatePropertyType::Int);
					ClassUnderTest->SetComparedToState("B", EStatePropertyType::Int);

					GivenState->SetInt("A", 36965);
					GivenState->SetInt("B", 400000);
					TestEqual("UStateQuery_CompareToStateValue::Query", ClassUnderTest->Query(GivenState), EStateQueryResult::Succeeded);

					GivenState->SetInt("A", -400000);
					TestEqual("UStateQuery_CompareToStateValue::Query", ClassUnderTest->Query(GivenState), EStateQueryResult::Succeeded);
				});
		});

	Describe("Successful queries for Float", [this]()
		{
			It("Should return success when the value defined is less than state value", [this]()
				{
					ClassUnderTest->SetComparisonOperation(EStateQueryCompareToOperation::LessThan);
					ClassUnderTest->SetQueriedState("A", EStatePropertyType::Float);
					ClassUnderTest->SetComparedToState("B", EStatePropertyType::Float);

					GivenState->SetFloat("A", 100.f);
					GivenState->SetFloat("B", 200.f);
					TestEqual("UStateQuery_CompareToStateValue::Query", ClassUnderTest->Query(GivenState), EStateQueryResult::Succeeded);
				});

			It("Should return success when the value defined is less than or equal to state value", [this]()
				{
					ClassUnderTest->SetComparisonOperation(EStateQueryCompareToOperation::LessThanOrEqualTo);
					ClassUnderTest->SetQueriedState("A", EStatePropertyType::Float);
					ClassUnderTest->SetComparedToState("B", EStatePropertyType::Float);

					GivenState->SetFloat("A", 101.f);
					GivenState->SetFloat("B", 202.f);
					TestEqual("UStateQuery_CompareToStateValue::Query", ClassUnderTest->Query(GivenState), EStateQueryResult::Succeeded);

					GivenState->SetFloat("B", 101.f);
					TestEqual("UStateQuery_CompareToStateValue::Query", ClassUnderTest->Query(GivenState), EStateQueryResult::Succeeded);
				});

			It("Should return success when the value defined is greater than state value", [this]()
				{
					ClassUnderTest->SetComparisonOperation(EStateQueryCompareToOperation::GreaterThan);
					ClassUnderTest->SetQueriedState("A", EStatePropertyType::Float);
					ClassUnderTest->SetComparedToState("B", EStatePropertyType::Float);

					GivenState->SetFloat("A", 30.f);
					GivenState->SetFloat("B", 10.f);
					TestEqual("UStateQuery_CompareToStateValue::Query", ClassUnderTest->Query(GivenState), EStateQueryResult::Succeeded);
				});

			It("Should return success when the value defined is greater than or equal to state value", [this]()
				{
					ClassUnderTest->SetComparisonOperation(EStateQueryCompareToOperation::GreaterThanOrEqualTo);
					ClassUnderTest->SetQueriedState("A", EStatePropertyType::Float);
					ClassUnderTest->SetComparedToState("B", EStatePropertyType::Float);

					GivenState->SetFloat("A", 30000.12f);
					GivenState->SetFloat("B", 29000.111f);
					TestEqual("UStateQuery_CompareToStateValue::Query", ClassUnderTest->Query(GivenState), EStateQueryResult::Succeeded);

					GivenState->SetFloat("B", 30000.12f);
					TestEqual("UStateQuery_CompareToStateValue::Query", ClassUnderTest->Query(GivenState), EStateQueryResult::Succeeded);
				});

			It("Should return success when the value defined is equal to the value", [this]()
				{
					ClassUnderTest->SetComparisonOperation(EStateQueryCompareToOperation::EqualTo);
					ClassUnderTest->SetQueriedState("A", EStatePropertyType::Float);
					ClassUnderTest->SetComparedToState("B", EStatePropertyType::Float);

					GivenState->SetFloat("A", 400004.f);
					GivenState->SetFloat("B", 400004.f);
					TestEqual("UStateQuery_CompareToStateValue::Query", ClassUnderTest->Query(GivenState), EStateQueryResult::Succeeded);
				});

			It("Should return success when the value defined is not equal to the value", [this]()
				{
					ClassUnderTest->SetComparisonOperation(EStateQueryCompareToOperation::NotEqualTo);
					ClassUnderTest->SetQueriedState("A", EStatePropertyType::Float);
					ClassUnderTest->SetComparedToState("B", EStatePropertyType::Float);

					GivenState->SetFloat("A", 36965.f);
					GivenState->SetFloat("B", 400000.f);
					TestEqual("UStateQuery_CompareToStateValue::Query", ClassUnderTest->Query(GivenState), EStateQueryResult::Succeeded);

					GivenState->SetFloat("A", -400000.f);
					TestEqual("UStateQuery_CompareToStateValue::Query", ClassUnderTest->Query(GivenState), EStateQueryResult::Succeeded);
				});

		});

	Describe("Mixing types", [this]()
		{
			const EStatePropertyType Types[] = {
				EStatePropertyType::Bool,
				EStatePropertyType::Class,
				EStatePropertyType::Enum,
				EStatePropertyType::Float,
				EStatePropertyType::Int,
				EStatePropertyType::Name,
				EStatePropertyType::Object,
				EStatePropertyType::Rotator,
				EStatePropertyType::String,
				EStatePropertyType::Vector
			};
			const int32 Size = int32(std::size(Types));

			for (int32 I = 0; I < Size; ++I)
			{
				for (int32 J = 0; J < Size; ++J)
				{
					if (I != J)
					{
						const auto A = Types[I];
						const auto B = Types[J];
						It(FString::Printf(TEXT("Should not compare two different expected types where A is %s and B is %s"), *UEnum::GetValueAsName(A).ToString(), *UEnum::GetValueAsName(B).ToString()), [this, A, B]()
							{
								ClassUnderTest->SetQueriedState("A", A);
								ClassUnderTest->SetComparedToState("B", B);
								TestEqual("UStateQuery_CompareToStateValue::Query", ClassUnderTest->Query(GivenState), EStateQueryResult::Invalid);
							});
					}
				}
			}
		});

	AfterEach([this]()
		{
			ClassUnderTest->ConditionalBeginDestroy();
			GivenState->ConditionalBeginDestroy();
		});
}
