#pragma once

#include <string>

// 현재 온도, 목성과 화성 사이의 거리를 기반으로 날씨를 예측하는 검증된 최첨단 기술을 구현한다.
// 이런 값이 제공되지 않아도 날씨를 예측할 수 있지만 정확도는 99%에 불과하다.
class WeatherPrediction
{
public:
	// Virtual 소멸자
	virtual ~WeatherPrediction();

	// 현재 온도를 화씨 단위로 설정한다.
	virtual void setCurrentTempFahrenheit(int temp);

	// 목성과 화성 사이의 현재 거리를 설정한다.
	virtual void setPositionOfJupiter(int distanceFromMars);
	
	// 내일 온도에 대한 예측값을 가져온다.
	virtual int getTomorrowTempFahrenheit() const;
	
	// 내일 비가 올 확률을 가져온다. 값이 1이면 확실히 비가 오고, 
    // 0이면 비가 오지 않는다는 것을 의미한다.
	virtual double getChanceOfRain() const;
	
	// 사용자에게 다음과 같은 포맷으로 결과를 출력한다:
	// Result: x.xx chance. Temp. xx
	virtual void showResult() const;
	
	// 현재 온도를 스트링값으로 리턴한다.
	virtual std::string getTemperature() const;

private:
	int mCurrentTempFahrenheit;
	int mDistanceFromMars;
};
