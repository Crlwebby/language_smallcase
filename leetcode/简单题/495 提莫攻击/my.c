int findPoisonedDuration(int* timeSeries, int timeSeriesSize, int duration){
    int sum = 0;
    for(int i = 1; i < timeSeriesSize; i++){
        if(timeSeries[i]-timeSeries[i-1]>=duration)
            sum += duration;
        else
            sum += timeSeries[i]-timeSeries[i-1];
    }
    return sum + duration;
}

//好无聊的题……看个go写的 加进去吧