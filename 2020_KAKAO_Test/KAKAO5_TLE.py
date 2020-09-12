# Each Case Fail to Solve : Time Over

# Time String -> Time Second
def convert_sec(time):
    time_sec = int(time[0:2]) * 3600 + int(time[3:5]) * 60 + int(time[6:8])
    return time_sec

# Time Second -> Time String
def convert_time(sec):
    hour = sec // 3600
    minute = (sec % 3600) // 60
    second = sec % 60

    if hour < 10:
        hour = "0" + str(hour)
    if minute < 10:
        minute = "0" + str(minute)
    if second < 10:
        second = "0" + str(second)

    time = str(hour) + ":" + str(minute) + ":" + str(second)
    
    return time

def solution(play_time, adv_time, logs):
    play_time_sec = convert_sec(play_time)
    adv_time_sec = convert_sec(adv_time)
    logs_sec = []

    # Making List of Logs : logs_sec = [(start_second, end_second) ,,, ]
    for log in logs:
        logs_sec.append((convert_sec(log[0:8]), convert_sec(log[9:17])))
    
    # Record Data of Views at Each Time
    record = [0] * play_time_sec

    # Record All View Logs
    for log in logs_sec:
        for t in range(log[0], log[1]):
            record[t] += 1

    # Get Max Viewer Time by Record
    max_time = (0,0)
    for time in range(play_time_sec):

        # if Over
        if time + adv_time_sec > play_time_sec:
            break

        # Count Data of Viewers
        count = 0

        # Count Total Viewers at Advertising Time
        for t in range(time, time+adv_time_sec):
            count += record[t]

        # Count Value is Max ?
        if count > max_time[1]:
            max_time = (time, count)

    return convert_time(max_time[0])

if __name__ == "__main__":
    play_time = "02:03:55"
    adv_time = "00:14:15"
    logs = ["01:20:15-01:45:14", "00:40:31-01:00:00", "00:25:50-00:48:29", "01:30:59-01:53:29", "01:37:44-02:02:30"]
    
    print(solution(play_time, adv_time, logs))