# 定义
v2x协议栈四层
接入层  
网络层
	V2X消息的收发
消息层
 	消息编解码 数据融合和处理
应用层
	逻辑运算、自动驾驶联合控制、预警播报、人机交互

补充一点金融知识
市场渗透率 = 销量，实际需求量 / 潜在需求量
毛利率=毛利/营业收入×100%=（主营业务收入-主营业务成本）/主营业务收入×100%
# V2x定位问题
## GNSS定位
GNSS 四颗卫星定位
x，y，z确定空间的一个点，还有一个需要进行授时 用于时间同步
V2X V2V时间同步  我的1点就是你的1点
GNSS定位精度可以达到米级
4颗卫星才能启动 GNSS冷启动大概需要两分钟
## 基站定位
基站定位是计算车载终端到基站的位置来进行定位，通过运营商网络获取移动终端的位置信息。（经纬度坐标等）
城市大概50-100米，城郊100-300米，乡村大概200-2000米，
## A-GPS
A-GPS是GNSS定位系列的一个补充，它最主要的应用在于解决GPS冷启动时间过长的这个问题，它可以将GNSS的首次定位时间（TTFF）缩短至18-30秒。在T-BOX和V2X中，很多厂商都有这样的需求和应用。
在A-GPS结合了基站和GNSS两者的长处，在A-GPS系统中，A-GPS服务器可以根据车载移动终端当前所在的小区和基站（蜂窝网络里的小区），确定正在其小区上空的GPS卫星，这样可以先确定一个大概的位置。然后根据这个大概的位置迅速的去寻找和捕获卫星，并将这些信息提供给车载移动终端。

具体的定位流程如下：

1.首先终端接收机把本身的位置信息发送给A-GPS位置服务器

2.A-GPS位置服务器把该位置信息相关的GPS信息发送给终端：GPS定位辅助信息，灵敏度辅助信息，工作状态信息。和移动终端计算的辅助信息，如GPS历书，修正数据，GPS星历等。

3.终端接收机根据位置服务器传输的信息，很快的捕捉到卫星，并可以接收GPS原始信号，进行解调。计算接收机到卫星的伪距。

4.最后通过网络侧计算或者终端侧计算算出终端的具体位置。

A-GPS传说中是由两种计算方式的，一种是在网络侧（基站侧），另一种是在终端侧。1.MSB: 定位计算由终端接收机完成，优点网络负担比较小，延时短，适合短时间的定位

2.MSA：定位计算由移动基站网络完成，然后再传送给终端接收机完成，优点对终端要求比较低，延时比较大，不适合高速行驶使用。

目前我看的A-GPS还都是放在终端进行定位计算的。不过至今为止我还有一点不明白的是，基站侧是怎么进行定位计算的呢？这算是边缘计算吗？基站真的是支持这个服务吗？会不会有不支持的呢？

希望这些问题在以后的工作中能慢慢的找到答案吧！

总结：A-GPS主要解决的问题就是冷启动时间过长。
## RTK
4. RTK

其实说起RTK，我的第一反应就是千寻。

RTK属于是所有GNSS系列定位方式里精度最高的了，据说可以达到厘米级的定位信息，可以准确识别出车道线的变更，几乎解决了V2X中最大的问题，但是它也是有缺点的就是，它有点贵。从成本控制的角度来讲，有些低配版的产品是不会考虑这种高精定位的方式的。

RTK主要分为四大组成部分：固定不动基准站部分，负责数据处理的控制中心部分，负责数据通信的线路部分，接收信息的用户部分。

RTK实现精准定位的过程大概如下：

首先确定基准站的个数和设定的位置，再以设定的基准站作为数据处理的基础来计算定位的准确度。
将误差改进数据发送给系统
用户部分对得到的定位信息进行实时的误差更正，并获得准确的定位信息
RTK中也使用了差分GPS技术，使用双频的GPS接收机，通过同步观测法来实现精准的定位和校验。

总结：对于RTK来说，它的优点和缺点都很明显。贵，但是有用。

在RTK部分，你说能解决V2X 的最大问题，解决的具体问题是什么呢？
超车，左转，碰撞等一些V2X场景需要准确识别车辆位置，同时对车道线的依赖程度很高。对目前的V2X场景算法来说，目前在有限的成本空间内实现高精定位是最大的问题。
依赖路侧基站提高定位精度是否是可行的呢
基站定位精度是几到几十米，对V2X来说，要亚米级的定位精度才可以。
按照标准来看，1.5m定位精度也是足够的。双频GPS不带RTK，你们有测量效果吗？
有测，空旷地带可以到0.5米，但是有遮挡的建筑物，树荫，环岛隧道等可能就有几米的误差了。目前我还是觉得RTK量产可能不太靠谱。
还是看市场需求把，目前大部分人的车都是满足基本定位导航就ok了，要想提高精度， RTK配合有IMU可以弥补短时间定位信号弱的缺点，但是价格就贵多了，这个除非大批量，不然没法降低价格
目前的想法是依赖高精地图哈哈哈哈
高精度地图也得依赖rtk啊
