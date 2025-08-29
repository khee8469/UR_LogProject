
#include "MyActor.h"

AMyActor::AMyActor()
{
	PrimaryActorTick.bCanEverTick = false;
	start.X = 0; start.Y = 0;
	end.X = 0; end.Y = 0;
	evCnt = 0;
	totDist = 0;
	dist = 0;
}

void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Create"));
	UE_LOG(LogTemp, Warning, TEXT("Start Position : %s"), *start.ToString());

	for (int i = 0; i < 10; ++i )
	{
		//이동
		Move();
		UE_LOG(LogTemp, Warning, TEXT("Current Position : %s"), *end.ToString());
		
		//이동거리
		dist = Distance(start, end);
		UE_LOG(LogTemp, Warning, TEXT("Cureent Moved Distance : %.1f"), dist);
		totDist += dist;
		start = end;
		//이벤트
		if (1 == (CreateEvent()))
		{
			++evCnt;
			UE_LOG(LogTemp, Warning, TEXT("Event"));
		}
	}

	// 이동거리 이벤트횟수 출력
	UE_LOG(LogTemp, Warning, TEXT("Total Distance : %.1f, Total Event : %d") , totDist, evCnt);
}

void AMyActor::Tick(float DeltaTime)
{

}

float AMyActor::Distance(FVector2D first, FVector2D second)
{
	float dx = second.X - first.X;
	float dy = second.Y - first.Y;
	return FMath::Sqrt(dx * dx + dy * dy);
}

void AMyActor::Move()
{
	end.X += Step();
	end.Y += Step();
}

int32 AMyActor::Step()
{
	return FMath::RandRange(0, 1);
}

int32 AMyActor::CreateEvent()
{
	return FMath::RandRange(0, 1);
}