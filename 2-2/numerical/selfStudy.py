list = [""]
st = ""
for i in list:
    st += (i if i != "" else "&nbsp") + ",|,"
st = st[:-3]

print(st)
l = len(st)
st = st.replace("&nbsp", "")
print([] if l == 0 else st.split(",|,"))