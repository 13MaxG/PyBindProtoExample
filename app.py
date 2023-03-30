import mymessages_pb2
import mylib

message = mymessages_pb2.Message()
message.name = "Lawrence"

message2 = mymessages_pb2.Message()
message2.ParseFromString(mylib.process(message.SerializeToString()))
print(message2.name)
