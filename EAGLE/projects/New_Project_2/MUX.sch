<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="9.1.2">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="mm" style="lines" multiple="1" display="yes" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="2" name="Route2" color="1" fill="3" visible="no" active="no"/>
<layer number="3" name="Route3" color="4" fill="3" visible="no" active="no"/>
<layer number="4" name="Route4" color="1" fill="4" visible="no" active="no"/>
<layer number="5" name="Route5" color="4" fill="4" visible="no" active="no"/>
<layer number="6" name="Route6" color="1" fill="8" visible="no" active="no"/>
<layer number="7" name="Route7" color="4" fill="8" visible="no" active="no"/>
<layer number="8" name="Route8" color="1" fill="2" visible="no" active="no"/>
<layer number="9" name="Route9" color="4" fill="2" visible="no" active="no"/>
<layer number="10" name="Route10" color="1" fill="7" visible="no" active="no"/>
<layer number="11" name="Route11" color="4" fill="7" visible="no" active="no"/>
<layer number="12" name="Route12" color="1" fill="5" visible="no" active="no"/>
<layer number="13" name="Route13" color="4" fill="5" visible="no" active="no"/>
<layer number="14" name="Route14" color="1" fill="6" visible="no" active="no"/>
<layer number="15" name="Route15" color="4" fill="6" visible="no" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="no" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="no" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="no" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="no" active="no"/>
<layer number="20" name="Dimension" color="15" fill="1" visible="no" active="no"/>
<layer number="21" name="tPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="22" name="bPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="23" name="tOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="24" name="bOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="25" name="tNames" color="7" fill="1" visible="no" active="no"/>
<layer number="26" name="bNames" color="7" fill="1" visible="no" active="no"/>
<layer number="27" name="tValues" color="7" fill="1" visible="no" active="no"/>
<layer number="28" name="bValues" color="7" fill="1" visible="no" active="no"/>
<layer number="29" name="tStop" color="7" fill="3" visible="no" active="no"/>
<layer number="30" name="bStop" color="7" fill="6" visible="no" active="no"/>
<layer number="31" name="tCream" color="7" fill="4" visible="no" active="no"/>
<layer number="32" name="bCream" color="7" fill="5" visible="no" active="no"/>
<layer number="33" name="tFinish" color="6" fill="3" visible="no" active="no"/>
<layer number="34" name="bFinish" color="6" fill="6" visible="no" active="no"/>
<layer number="35" name="tGlue" color="7" fill="4" visible="no" active="no"/>
<layer number="36" name="bGlue" color="7" fill="5" visible="no" active="no"/>
<layer number="37" name="tTest" color="7" fill="1" visible="no" active="no"/>
<layer number="38" name="bTest" color="7" fill="1" visible="no" active="no"/>
<layer number="39" name="tKeepout" color="4" fill="11" visible="no" active="no"/>
<layer number="40" name="bKeepout" color="1" fill="11" visible="no" active="no"/>
<layer number="41" name="tRestrict" color="4" fill="10" visible="no" active="no"/>
<layer number="42" name="bRestrict" color="1" fill="10" visible="no" active="no"/>
<layer number="43" name="vRestrict" color="2" fill="10" visible="no" active="no"/>
<layer number="44" name="Drills" color="7" fill="1" visible="no" active="no"/>
<layer number="45" name="Holes" color="7" fill="1" visible="no" active="no"/>
<layer number="46" name="Milling" color="3" fill="1" visible="no" active="no"/>
<layer number="47" name="Measures" color="7" fill="1" visible="no" active="no"/>
<layer number="48" name="Document" color="7" fill="1" visible="no" active="no"/>
<layer number="49" name="Reference" color="7" fill="1" visible="no" active="no"/>
<layer number="51" name="tDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="52" name="bDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="88" name="SimResults" color="9" fill="1" visible="yes" active="yes"/>
<layer number="89" name="SimProbes" color="9" fill="1" visible="yes" active="yes"/>
<layer number="90" name="Modules" color="5" fill="1" visible="yes" active="yes"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="BSS138">
<description>&lt;N-channel MOSFET,BSS138 0.2A 50V&lt;/b&gt;&lt;p&gt;
&lt;author&gt;Created by SamacSys&lt;/author&gt;</description>
<packages>
<package name="SOT95P240X120-3N">
<description>&lt;b&gt;SOT-23 (TO-236)-3&lt;/b&gt;&lt;br&gt;
</description>
<smd name="1" x="-1.2" y="0.95" dx="1" dy="0.7" layer="1"/>
<smd name="2" x="-1.2" y="-0.95" dx="1" dy="0.7" layer="1"/>
<smd name="3" x="1.2" y="0" dx="1" dy="0.7" layer="1"/>
<text x="0" y="0" size="1.27" layer="25" align="center">&gt;NAME</text>
<text x="0" y="0" size="1.27" layer="27" align="center">&gt;VALUE</text>
<wire x1="-1.95" y1="1.81" x2="1.95" y2="1.81" width="0.05" layer="51"/>
<wire x1="1.95" y1="1.81" x2="1.95" y2="-1.81" width="0.05" layer="51"/>
<wire x1="1.95" y1="-1.81" x2="-1.95" y2="-1.81" width="0.05" layer="51"/>
<wire x1="-1.95" y1="-1.81" x2="-1.95" y2="1.81" width="0.05" layer="51"/>
<wire x1="-0.662" y1="1.46" x2="0.662" y2="1.46" width="0.1" layer="51"/>
<wire x1="0.662" y1="1.46" x2="0.662" y2="-1.46" width="0.1" layer="51"/>
<wire x1="0.662" y1="-1.46" x2="-0.662" y2="-1.46" width="0.1" layer="51"/>
<wire x1="-0.662" y1="-1.46" x2="-0.662" y2="1.46" width="0.1" layer="51"/>
<wire x1="-0.662" y1="0.51" x2="0.288" y2="1.46" width="0.1" layer="51"/>
<wire x1="-0.35" y1="1.46" x2="0.35" y2="1.46" width="0.2" layer="21"/>
<wire x1="0.35" y1="1.46" x2="0.35" y2="-1.46" width="0.2" layer="21"/>
<wire x1="0.35" y1="-1.46" x2="-0.35" y2="-1.46" width="0.2" layer="21"/>
<wire x1="-0.35" y1="-1.46" x2="-0.35" y2="1.46" width="0.2" layer="21"/>
<wire x1="-1.7" y1="1.55" x2="-0.7" y2="1.55" width="0.2" layer="21"/>
</package>
</packages>
<symbols>
<symbol name="BSS138">
<wire x1="5.08" y1="2.54" x2="15.24" y2="2.54" width="0.254" layer="94"/>
<wire x1="15.24" y1="-5.08" x2="15.24" y2="2.54" width="0.254" layer="94"/>
<wire x1="15.24" y1="-5.08" x2="5.08" y2="-5.08" width="0.254" layer="94"/>
<wire x1="5.08" y1="2.54" x2="5.08" y2="-5.08" width="0.254" layer="94"/>
<text x="16.51" y="7.62" size="1.778" layer="95" align="center-left">&gt;NAME</text>
<text x="16.51" y="5.08" size="1.778" layer="96" align="center-left">&gt;VALUE</text>
<pin name="G" x="0" y="0" length="middle"/>
<pin name="S" x="0" y="-2.54" length="middle"/>
<pin name="D" x="20.32" y="0" length="middle" rot="R180"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="BSS138" prefix="Q">
<description>&lt;b&gt;N-channel MOSFET,BSS138 0.2A 50V&lt;/b&gt;&lt;p&gt;
Source: &lt;a href="https://www.onsemi.com/pub/Collateral/BSS138-D.PDF"&gt; Datasheet &lt;/a&gt;</description>
<gates>
<gate name="G$1" symbol="BSS138" x="0" y="0"/>
</gates>
<devices>
<device name="" package="SOT95P240X120-3N">
<connects>
<connect gate="G$1" pin="D" pad="3"/>
<connect gate="G$1" pin="G" pad="1"/>
<connect gate="G$1" pin="S" pad="2"/>
</connects>
<technologies>
<technology name="">
<attribute name="DESCRIPTION" value="N-channel MOSFET,BSS138 0.2A 50V" constant="no"/>
<attribute name="HEIGHT" value="1.2mm" constant="no"/>
<attribute name="MANUFACTURER_NAME" value="ON Semiconductor" constant="no"/>
<attribute name="MANUFACTURER_PART_NUMBER" value="BSS138" constant="no"/>
<attribute name="MOUSER_PART_NUMBER" value="512-BSS138" constant="no"/>
<attribute name="MOUSER_PRICE-STOCK" value="" constant="no"/>
<attribute name="RS_PART_NUMBER" value="1241694" constant="no"/>
<attribute name="RS_PRICE-STOCK" value="http://uk.rs-online.com/web/p/products/1241694" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="TC74HC595AP(F)">
<description>&lt;IC,CMOS logic,DIP16,SHIFT REGISTERS&lt;/b&gt;&lt;p&gt;
&lt;author&gt;Created by SamacSys&lt;/author&gt;</description>
<packages>
<package name="DIP762W60P254L1925H445Q16N">
<description>&lt;b&gt;DIP-16-P-300-2.54A_1-1&lt;/b&gt;&lt;br&gt;
</description>
<pad name="1" x="-3.81" y="8.89" drill="0.8" diameter="1.2" shape="square"/>
<pad name="2" x="-3.81" y="6.35" drill="0.8" diameter="1.2"/>
<pad name="3" x="-3.81" y="3.81" drill="0.8" diameter="1.2"/>
<pad name="4" x="-3.81" y="1.27" drill="0.8" diameter="1.2"/>
<pad name="5" x="-3.81" y="-1.27" drill="0.8" diameter="1.2"/>
<pad name="6" x="-3.81" y="-3.81" drill="0.8" diameter="1.2"/>
<pad name="7" x="-3.81" y="-6.35" drill="0.8" diameter="1.2"/>
<pad name="8" x="-3.81" y="-8.89" drill="0.8" diameter="1.2"/>
<pad name="9" x="3.81" y="-8.89" drill="0.8" diameter="1.2"/>
<pad name="10" x="3.81" y="-6.35" drill="0.8" diameter="1.2"/>
<pad name="11" x="3.81" y="-3.81" drill="0.8" diameter="1.2"/>
<pad name="12" x="3.81" y="-1.27" drill="0.8" diameter="1.2"/>
<pad name="13" x="3.81" y="1.27" drill="0.8" diameter="1.2"/>
<pad name="14" x="3.81" y="3.81" drill="0.8" diameter="1.2"/>
<pad name="15" x="3.81" y="6.35" drill="0.8" diameter="1.2"/>
<pad name="16" x="3.81" y="8.89" drill="0.8" diameter="1.2"/>
<text x="0" y="0" size="1.27" layer="25" align="center">&gt;NAME</text>
<text x="0" y="0" size="1.27" layer="27" align="center">&gt;VALUE</text>
<wire x1="-4.66" y1="9.975" x2="4.66" y2="9.975" width="0.05" layer="51"/>
<wire x1="4.66" y1="9.975" x2="4.66" y2="-9.975" width="0.05" layer="51"/>
<wire x1="4.66" y1="-9.975" x2="-4.66" y2="-9.975" width="0.05" layer="51"/>
<wire x1="-4.66" y1="-9.975" x2="-4.66" y2="9.975" width="0.05" layer="51"/>
<wire x1="-3.3" y1="9.725" x2="3.3" y2="9.725" width="0.1" layer="51"/>
<wire x1="3.3" y1="9.725" x2="3.3" y2="-9.725" width="0.1" layer="51"/>
<wire x1="3.3" y1="-9.725" x2="-3.3" y2="-9.725" width="0.1" layer="51"/>
<wire x1="-3.3" y1="-9.725" x2="-3.3" y2="9.725" width="0.1" layer="51"/>
<wire x1="-3.3" y1="8.455" x2="-2.03" y2="9.725" width="0.1" layer="51"/>
<wire x1="-4.41" y1="9.725" x2="3.3" y2="9.725" width="0.2" layer="21"/>
<wire x1="-3.3" y1="-9.725" x2="3.3" y2="-9.725" width="0.2" layer="21"/>
</package>
</packages>
<symbols>
<symbol name="TC74HC595AP(F)">
<wire x1="5.08" y1="2.54" x2="22.86" y2="2.54" width="0.254" layer="94"/>
<wire x1="22.86" y1="-20.32" x2="22.86" y2="2.54" width="0.254" layer="94"/>
<wire x1="22.86" y1="-20.32" x2="5.08" y2="-20.32" width="0.254" layer="94"/>
<wire x1="5.08" y1="2.54" x2="5.08" y2="-20.32" width="0.254" layer="94"/>
<text x="24.13" y="7.62" size="1.778" layer="95" align="center-left">&gt;NAME</text>
<text x="24.13" y="5.08" size="1.778" layer="96" align="center-left">&gt;VALUE</text>
<pin name="QB" x="0" y="0" length="middle"/>
<pin name="QC" x="0" y="-2.54" length="middle"/>
<pin name="QD" x="0" y="-5.08" length="middle"/>
<pin name="QE" x="0" y="-7.62" length="middle"/>
<pin name="QF" x="0" y="-10.16" length="middle"/>
<pin name="QG" x="0" y="-12.7" length="middle"/>
<pin name="QH" x="0" y="-15.24" length="middle"/>
<pin name="GND" x="0" y="-17.78" length="middle"/>
<pin name="VCC" x="27.94" y="0" length="middle" rot="R180"/>
<pin name="QA" x="27.94" y="-2.54" length="middle" rot="R180"/>
<pin name="SI" x="27.94" y="-5.08" length="middle" rot="R180"/>
<pin name="!G" x="27.94" y="-7.62" length="middle" rot="R180"/>
<pin name="RCK" x="27.94" y="-10.16" length="middle" rot="R180"/>
<pin name="SCK" x="27.94" y="-12.7" length="middle" rot="R180"/>
<pin name="!SCLR" x="27.94" y="-15.24" length="middle" rot="R180"/>
<pin name="QH'" x="27.94" y="-17.78" length="middle" rot="R180"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="TC74HC595AP(F)" prefix="IC">
<description>&lt;b&gt;IC,CMOS logic,DIP16,SHIFT REGISTERS&lt;/b&gt;&lt;p&gt;
Source: &lt;a href="http://toshiba.semicon-storage.com/info/docget.jsp?did=16512&amp;prodName=TC74HC595AP"&gt; Datasheet &lt;/a&gt;</description>
<gates>
<gate name="G$1" symbol="TC74HC595AP(F)" x="0" y="0"/>
</gates>
<devices>
<device name="" package="DIP762W60P254L1925H445Q16N">
<connects>
<connect gate="G$1" pin="!G" pad="13"/>
<connect gate="G$1" pin="!SCLR" pad="10"/>
<connect gate="G$1" pin="GND" pad="8"/>
<connect gate="G$1" pin="QA" pad="15"/>
<connect gate="G$1" pin="QB" pad="1"/>
<connect gate="G$1" pin="QC" pad="2"/>
<connect gate="G$1" pin="QD" pad="3"/>
<connect gate="G$1" pin="QE" pad="4"/>
<connect gate="G$1" pin="QF" pad="5"/>
<connect gate="G$1" pin="QG" pad="6"/>
<connect gate="G$1" pin="QH" pad="7"/>
<connect gate="G$1" pin="QH'" pad="9"/>
<connect gate="G$1" pin="RCK" pad="12"/>
<connect gate="G$1" pin="SCK" pad="11"/>
<connect gate="G$1" pin="SI" pad="14"/>
<connect gate="G$1" pin="VCC" pad="16"/>
</connects>
<technologies>
<technology name="">
<attribute name="DESCRIPTION" value="IC,CMOS logic,DIP16,SHIFT REGISTERS" constant="no"/>
<attribute name="HEIGHT" value="4.45mm" constant="no"/>
<attribute name="MANUFACTURER_NAME" value="Toshiba" constant="no"/>
<attribute name="MANUFACTURER_PART_NUMBER" value="TC74HC595AP(F)" constant="no"/>
<attribute name="MOUSER_PART_NUMBER" value="N/A" constant="no"/>
<attribute name="MOUSER_PRICE-STOCK" value="https://www.mouser.com/Search/Refine.aspx?Keyword=N%2FA" constant="no"/>
<attribute name="RS_PART_NUMBER" value="5400095P" constant="no"/>
<attribute name="RS_PRICE-STOCK" value="http://au.rs-online.com/web/p/products/5400095P" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="supply1" urn="urn:adsk.eagle:library:371">
<description>&lt;b&gt;Supply Symbols&lt;/b&gt;&lt;p&gt;
 GND, VCC, 0V, +5V, -5V, etc.&lt;p&gt;
 Please keep in mind, that these devices are necessary for the
 automatic wiring of the supply signals.&lt;p&gt;
 The pin name defined in the symbol is identical to the net which is to be wired automatically.&lt;p&gt;
 In this library the device names are the same as the pin names of the symbols, therefore the correct signal names appear next to the supply symbols in the schematic.&lt;p&gt;
 &lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
</packages>
<symbols>
<symbol name="GND" urn="urn:adsk.eagle:symbol:26925/1" library_version="1">
<wire x1="-1.905" y1="0" x2="1.905" y2="0" width="0.254" layer="94"/>
<text x="-2.54" y="-2.54" size="1.778" layer="96">&gt;VALUE</text>
<pin name="GND" x="0" y="2.54" visible="off" length="short" direction="sup" rot="R270"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="GND" urn="urn:adsk.eagle:component:26954/1" prefix="GND" library_version="1">
<description>&lt;b&gt;SUPPLY SYMBOL&lt;/b&gt;</description>
<gates>
<gate name="1" symbol="GND" x="0" y="0"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="con-molex" urn="urn:adsk.eagle:library:165">
<description>&lt;b&gt;Molex Connectors&lt;/b&gt;&lt;p&gt;
&lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
<package name="22-23-2081" library_version="2">
<description>&lt;b&gt;KK® 254 Solid Header, Vertical, with Friction Lock, 8 Circuits, Tin (Sn) Plating&lt;/b&gt;&lt;p&gt;&lt;a href =http://www.molex.com/pdm_docs/sd/022232081_sd.pdf&gt;Datasheet &lt;/a&gt;</description>
<wire x1="-10.16" y1="3.175" x2="10.16" y2="3.175" width="0.254" layer="21"/>
<wire x1="10.16" y1="3.175" x2="10.16" y2="1.27" width="0.254" layer="21"/>
<wire x1="10.16" y1="1.27" x2="10.16" y2="-3.175" width="0.254" layer="21"/>
<wire x1="10.16" y1="-3.175" x2="-10.16" y2="-3.175" width="0.254" layer="21"/>
<wire x1="-10.16" y1="-3.175" x2="-10.16" y2="1.27" width="0.254" layer="21"/>
<wire x1="-10.16" y1="1.27" x2="-10.16" y2="3.175" width="0.254" layer="21"/>
<wire x1="-10.16" y1="1.27" x2="10.16" y2="1.27" width="0.254" layer="21"/>
<pad name="1" x="-8.89" y="0" drill="1" shape="long" rot="R90"/>
<pad name="2" x="-6.35" y="0" drill="1" shape="long" rot="R90"/>
<pad name="3" x="-3.81" y="0" drill="1" shape="long" rot="R90"/>
<pad name="4" x="-1.27" y="0" drill="1" shape="long" rot="R90"/>
<pad name="5" x="1.27" y="0" drill="1" shape="long" rot="R90"/>
<pad name="6" x="3.81" y="0" drill="1" shape="long" rot="R90"/>
<pad name="7" x="6.35" y="0" drill="1" shape="long" rot="R90"/>
<pad name="8" x="8.89" y="0" drill="1" shape="long" rot="R90"/>
<text x="-10.16" y="3.81" size="1.016" layer="25" ratio="10">&gt;NAME</text>
<text x="-10.16" y="-5.08" size="1.016" layer="27" ratio="10">&gt;VALUE</text>
</package>
<package name="22-23-2061" library_version="2">
<description>&lt;b&gt;KK® 254 Solid Header, Vertical, with Friction Lock, 6 Circuits, Tin (Sn) Plating&lt;/b&gt;&lt;p&gt;&lt;a href =http://www.molex.com/pdm_docs/sd/022232061_sd.pdf&gt;Datasheet &lt;/a&gt;</description>
<wire x1="-7.62" y1="3.175" x2="7.62" y2="3.175" width="0.254" layer="21"/>
<wire x1="7.62" y1="3.175" x2="7.62" y2="1.27" width="0.254" layer="21"/>
<wire x1="7.62" y1="1.27" x2="7.62" y2="-3.175" width="0.254" layer="21"/>
<wire x1="7.62" y1="-3.175" x2="-7.62" y2="-3.175" width="0.254" layer="21"/>
<wire x1="-7.62" y1="-3.175" x2="-7.62" y2="1.27" width="0.254" layer="21"/>
<wire x1="-7.62" y1="1.27" x2="-7.62" y2="3.175" width="0.254" layer="21"/>
<wire x1="-7.62" y1="1.27" x2="7.62" y2="1.27" width="0.254" layer="21"/>
<pad name="1" x="-6.35" y="0" drill="1" shape="long" rot="R90"/>
<pad name="2" x="-3.81" y="0" drill="1" shape="long" rot="R90"/>
<pad name="3" x="-1.27" y="0" drill="1" shape="long" rot="R90"/>
<pad name="4" x="1.27" y="0" drill="1" shape="long" rot="R90"/>
<pad name="5" x="3.81" y="0" drill="1" shape="long" rot="R90"/>
<pad name="6" x="6.35" y="0" drill="1" shape="long" rot="R90"/>
<text x="-7.62" y="3.81" size="1.016" layer="25" ratio="10">&gt;NAME</text>
<text x="-7.62" y="-5.08" size="1.016" layer="27" ratio="10">&gt;VALUE</text>
</package>
</packages>
<symbols>
<symbol name="MV" library_version="2">
<wire x1="1.27" y1="0" x2="0" y2="0" width="0.6096" layer="94"/>
<text x="2.54" y="-0.762" size="1.524" layer="95">&gt;NAME</text>
<text x="-0.762" y="1.397" size="1.778" layer="96">&gt;VALUE</text>
<pin name="S" x="-2.54" y="0" visible="off" length="short" direction="pas"/>
</symbol>
<symbol name="M" library_version="2">
<wire x1="1.27" y1="0" x2="0" y2="0" width="0.6096" layer="94"/>
<text x="2.54" y="-0.762" size="1.524" layer="95">&gt;NAME</text>
<pin name="S" x="-2.54" y="0" visible="off" length="short" direction="pas"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="22-23-2081" prefix="X" library_version="2">
<description>.100" (2.54mm) Center Header - 8 Pin</description>
<gates>
<gate name="-1" symbol="MV" x="0" y="7.62" addlevel="always" swaplevel="1"/>
<gate name="-2" symbol="M" x="0" y="5.08" addlevel="always" swaplevel="1"/>
<gate name="-3" symbol="M" x="0" y="2.54" addlevel="always" swaplevel="1"/>
<gate name="-4" symbol="M" x="0" y="0" addlevel="always" swaplevel="1"/>
<gate name="-5" symbol="M" x="0" y="-2.54" addlevel="always" swaplevel="1"/>
<gate name="-6" symbol="M" x="0" y="-5.08" addlevel="always" swaplevel="1"/>
<gate name="-7" symbol="M" x="0" y="-7.62" addlevel="always" swaplevel="1"/>
<gate name="-8" symbol="M" x="0" y="-10.16" addlevel="always" swaplevel="1"/>
</gates>
<devices>
<device name="" package="22-23-2081">
<connects>
<connect gate="-1" pin="S" pad="1"/>
<connect gate="-2" pin="S" pad="2"/>
<connect gate="-3" pin="S" pad="3"/>
<connect gate="-4" pin="S" pad="4"/>
<connect gate="-5" pin="S" pad="5"/>
<connect gate="-6" pin="S" pad="6"/>
<connect gate="-7" pin="S" pad="7"/>
<connect gate="-8" pin="S" pad="8"/>
</connects>
<technologies>
<technology name="">
<attribute name="MF" value="MOLEX" constant="no"/>
<attribute name="MPN" value="22-23-2081" constant="no"/>
<attribute name="OC_FARNELL" value="1756826" constant="no"/>
<attribute name="OC_NEWARK" value="01C7592" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="22-23-2061" prefix="X" uservalue="yes" library_version="2">
<description>.100" (2.54mm) Center Header - 6 Pin</description>
<gates>
<gate name="-1" symbol="MV" x="0" y="5.08" addlevel="always" swaplevel="1"/>
<gate name="-2" symbol="M" x="0" y="2.54" addlevel="always" swaplevel="1"/>
<gate name="-3" symbol="M" x="0" y="0" addlevel="always" swaplevel="1"/>
<gate name="-4" symbol="M" x="0" y="-2.54" addlevel="always" swaplevel="1"/>
<gate name="-5" symbol="M" x="0" y="-5.08" addlevel="always" swaplevel="1"/>
<gate name="-6" symbol="M" x="0" y="-7.62" addlevel="always" swaplevel="1"/>
</gates>
<devices>
<device name="" package="22-23-2061">
<connects>
<connect gate="-1" pin="S" pad="1"/>
<connect gate="-2" pin="S" pad="2"/>
<connect gate="-3" pin="S" pad="3"/>
<connect gate="-4" pin="S" pad="4"/>
<connect gate="-5" pin="S" pad="5"/>
<connect gate="-6" pin="S" pad="6"/>
</connects>
<technologies>
<technology name="">
<attribute name="MF" value="MOLEX" constant="no"/>
<attribute name="MPN" value="22-23-2061" constant="no"/>
<attribute name="OC_FARNELL" value="1462922" constant="no"/>
<attribute name="OC_NEWARK" value="27C1933" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="CFR-25JB-52-2K2">
<description>&lt;Carbon Film Resistors - Through Hole 1/4W 2.2K Ohm 5%&lt;/b&gt;&lt;p&gt;
&lt;author&gt;Created by SamacSys&lt;/author&gt;</description>
<packages>
<package name="RESAD1590W60L630D240">
<description>&lt;b&gt;CFR-25&lt;/b&gt;&lt;br&gt;
</description>
<pad name="1" x="0" y="0" drill="0.8" diameter="1.2"/>
<pad name="2" x="15.9" y="0" drill="0.8" diameter="1.2"/>
<text x="0" y="0" size="1.27" layer="25" align="center">&gt;NAME</text>
<text x="0" y="0" size="1.27" layer="27" align="center">&gt;VALUE</text>
<wire x1="-0.85" y1="1.55" x2="16.75" y2="1.55" width="0.05" layer="51"/>
<wire x1="16.75" y1="1.55" x2="16.75" y2="-1.55" width="0.05" layer="51"/>
<wire x1="16.75" y1="-1.55" x2="-0.85" y2="-1.55" width="0.05" layer="51"/>
<wire x1="-0.85" y1="-1.55" x2="-0.85" y2="1.55" width="0.05" layer="51"/>
<wire x1="4.8" y1="1.2" x2="11.1" y2="1.2" width="0.1" layer="51"/>
<wire x1="11.1" y1="1.2" x2="11.1" y2="-1.2" width="0.1" layer="51"/>
<wire x1="11.1" y1="-1.2" x2="4.8" y2="-1.2" width="0.1" layer="51"/>
<wire x1="4.8" y1="-1.2" x2="4.8" y2="1.2" width="0.1" layer="51"/>
<wire x1="0" y1="0" x2="4.8" y2="0" width="0.1" layer="51"/>
<wire x1="11.1" y1="0" x2="15.9" y2="0" width="0.1" layer="51"/>
<wire x1="4.8" y1="1.2" x2="11.1" y2="1.2" width="0.2" layer="21"/>
<wire x1="11.1" y1="1.2" x2="11.1" y2="-1.2" width="0.2" layer="21"/>
<wire x1="11.1" y1="-1.2" x2="4.8" y2="-1.2" width="0.2" layer="21"/>
<wire x1="4.8" y1="-1.2" x2="4.8" y2="1.2" width="0.2" layer="21"/>
<wire x1="0.95" y1="0" x2="4.8" y2="0" width="0.2" layer="21"/>
<wire x1="11.1" y1="0" x2="14.95" y2="0" width="0.2" layer="21"/>
</package>
</packages>
<symbols>
<symbol name="CFR-25JB-52-2K2">
<wire x1="5.08" y1="1.27" x2="12.7" y2="1.27" width="0.254" layer="94"/>
<wire x1="12.7" y1="-1.27" x2="12.7" y2="1.27" width="0.254" layer="94"/>
<wire x1="12.7" y1="-1.27" x2="5.08" y2="-1.27" width="0.254" layer="94"/>
<wire x1="5.08" y1="1.27" x2="5.08" y2="-1.27" width="0.254" layer="94"/>
<text x="13.97" y="6.35" size="1.778" layer="95" align="center-left">&gt;NAME</text>
<text x="13.97" y="3.81" size="1.778" layer="96" align="center-left">&gt;VALUE</text>
<pin name="1" x="0" y="0" visible="pad" length="middle"/>
<pin name="2" x="17.78" y="0" visible="pad" length="middle" rot="R180"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="CFR-25JB-52-2K2" prefix="R">
<description>&lt;b&gt;Carbon Film Resistors - Through Hole 1/4W 2.2K Ohm 5%&lt;/b&gt;&lt;p&gt;
Source: &lt;a href="http://www.yageo.com/documents/recent/Yageo LR_CFR_2013.pdf"&gt; Datasheet &lt;/a&gt;</description>
<gates>
<gate name="G$1" symbol="CFR-25JB-52-2K2" x="0" y="0"/>
</gates>
<devices>
<device name="" package="RESAD1590W60L630D240">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
</connects>
<technologies>
<technology name="">
<attribute name="DESCRIPTION" value="Carbon Film Resistors - Through Hole 1/4W 2.2K Ohm 5%" constant="no"/>
<attribute name="HEIGHT" value="mm" constant="no"/>
<attribute name="MANUFACTURER_NAME" value="YAGEO (PHYCOMP)" constant="no"/>
<attribute name="MANUFACTURER_PART_NUMBER" value="CFR-25JB-52-2K2" constant="no"/>
<attribute name="MOUSER_PART_NUMBER" value="603-CFR-25JB-52-2K2" constant="no"/>
<attribute name="MOUSER_PRICE-STOCK" value="https://www.mouser.com/Search/Refine.aspx?Keyword=603-CFR-25JB-52-2K2" constant="no"/>
<attribute name="RS_PART_NUMBER" value="603-CFR-25JB-52-2K2" constant="no"/>
<attribute name="RS_PRICE-STOCK" value="https://www.mouser.com/Search/Refine.aspx?Keyword=603-CFR-25JB-52-2K2" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
</libraries>
<attributes>
</attributes>
<variantdefs>
</variantdefs>
<classes>
<class number="0" name="default" width="0" drill="0">
</class>
</classes>
<parts>
<part name="Q1" library="BSS138" deviceset="BSS138" device=""/>
<part name="Q2" library="BSS138" deviceset="BSS138" device=""/>
<part name="Q3" library="BSS138" deviceset="BSS138" device=""/>
<part name="Q4" library="BSS138" deviceset="BSS138" device=""/>
<part name="Q5" library="BSS138" deviceset="BSS138" device=""/>
<part name="Q6" library="BSS138" deviceset="BSS138" device=""/>
<part name="IC1" library="TC74HC595AP(F)" deviceset="TC74HC595AP(F)" device=""/>
<part name="GND1" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="IN" library="con-molex" library_urn="urn:adsk.eagle:library:165" deviceset="22-23-2081" device=""/>
<part name="GND2" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="R1" library="CFR-25JB-52-2K2" deviceset="CFR-25JB-52-2K2" device=""/>
<part name="R2" library="CFR-25JB-52-2K2" deviceset="CFR-25JB-52-2K2" device=""/>
<part name="R3" library="CFR-25JB-52-2K2" deviceset="CFR-25JB-52-2K2" device=""/>
<part name="R4" library="CFR-25JB-52-2K2" deviceset="CFR-25JB-52-2K2" device=""/>
<part name="R5" library="CFR-25JB-52-2K2" deviceset="CFR-25JB-52-2K2" device=""/>
<part name="R6" library="CFR-25JB-52-2K2" deviceset="CFR-25JB-52-2K2" device=""/>
<part name="OUT" library="con-molex" library_urn="urn:adsk.eagle:library:165" deviceset="22-23-2061" device=""/>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
<instance part="Q1" gate="G$1" x="43.18" y="93.98"/>
<instance part="Q2" gate="G$1" x="43.18" y="83.82"/>
<instance part="Q3" gate="G$1" x="43.18" y="73.66"/>
<instance part="Q4" gate="G$1" x="43.18" y="63.5"/>
<instance part="Q5" gate="G$1" x="43.18" y="53.34"/>
<instance part="Q6" gate="G$1" x="43.18" y="43.18"/>
<instance part="IC1" gate="G$1" x="25.4" y="58.42" rot="R180"/>
<instance part="GND1" gate="1" x="20.32" y="83.82"/>
<instance part="IN" gate="-1" x="-22.86" y="73.66" rot="MR0"/>
<instance part="IN" gate="-2" x="-22.86" y="71.12" rot="MR0"/>
<instance part="IN" gate="-3" x="-22.86" y="68.58" rot="MR0"/>
<instance part="IN" gate="-4" x="-22.86" y="66.04" rot="MR0"/>
<instance part="IN" gate="-5" x="-22.86" y="63.5" rot="MR0"/>
<instance part="IN" gate="-6" x="-22.86" y="60.96" rot="MR0"/>
<instance part="IN" gate="-7" x="-22.86" y="58.42" rot="MR0"/>
<instance part="IN" gate="-8" x="-22.86" y="55.88" rot="MR0"/>
<instance part="GND2" gate="1" x="-17.78" y="50.8"/>
<instance part="R1" gate="G$1" x="66.04" y="101.6" rot="R90"/>
<instance part="R2" gate="G$1" x="71.12" y="101.6" rot="R90"/>
<instance part="R3" gate="G$1" x="76.2" y="101.6" rot="R90"/>
<instance part="R4" gate="G$1" x="81.28" y="101.6" rot="R90"/>
<instance part="R5" gate="G$1" x="86.36" y="101.6" rot="R90"/>
<instance part="R6" gate="G$1" x="91.44" y="101.6" rot="R90"/>
<instance part="OUT" gate="-1" x="104.14" y="78.74"/>
<instance part="OUT" gate="-2" x="104.14" y="76.2"/>
<instance part="OUT" gate="-3" x="104.14" y="73.66"/>
<instance part="OUT" gate="-4" x="104.14" y="71.12"/>
<instance part="OUT" gate="-5" x="104.14" y="68.58"/>
<instance part="OUT" gate="-6" x="104.14" y="66.04"/>
</instances>
<busses>
</busses>
<nets>
<net name="N$4" class="0">
<segment>
<pinref part="Q5" gate="G$1" pin="G"/>
<wire x1="40.64" y1="53.34" x2="43.18" y2="53.34" width="0.1524" layer="91"/>
<wire x1="40.64" y1="53.34" x2="33.02" y2="53.34" width="0.1524" layer="91"/>
<wire x1="33.02" y1="53.34" x2="33.02" y2="60.96" width="0.1524" layer="91"/>
<pinref part="IC1" gate="G$1" pin="QC"/>
<wire x1="33.02" y1="60.96" x2="25.4" y2="60.96" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$2" class="0">
<segment>
<pinref part="Q6" gate="G$1" pin="G"/>
<wire x1="43.18" y1="43.18" x2="30.48" y2="43.18" width="0.1524" layer="91"/>
<wire x1="30.48" y1="43.18" x2="30.48" y2="58.42" width="0.1524" layer="91"/>
<pinref part="IC1" gate="G$1" pin="QB"/>
<wire x1="30.48" y1="58.42" x2="25.4" y2="58.42" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$3" class="0">
<segment>
<pinref part="Q4" gate="G$1" pin="G"/>
<pinref part="IC1" gate="G$1" pin="QD"/>
<wire x1="43.18" y1="63.5" x2="25.4" y2="63.5" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$5" class="0">
<segment>
<pinref part="Q1" gate="G$1" pin="G"/>
<wire x1="43.18" y1="93.98" x2="30.48" y2="93.98" width="0.1524" layer="91"/>
<wire x1="30.48" y1="93.98" x2="30.48" y2="71.12" width="0.1524" layer="91"/>
<pinref part="IC1" gate="G$1" pin="QG"/>
<wire x1="30.48" y1="71.12" x2="25.4" y2="71.12" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$6" class="0">
<segment>
<pinref part="Q2" gate="G$1" pin="G"/>
<wire x1="43.18" y1="83.82" x2="33.02" y2="83.82" width="0.1524" layer="91"/>
<wire x1="33.02" y1="83.82" x2="33.02" y2="68.58" width="0.1524" layer="91"/>
<pinref part="IC1" gate="G$1" pin="QF"/>
<wire x1="33.02" y1="68.58" x2="25.4" y2="68.58" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$7" class="0">
<segment>
<pinref part="Q3" gate="G$1" pin="G"/>
<wire x1="43.18" y1="73.66" x2="35.56" y2="73.66" width="0.1524" layer="91"/>
<wire x1="35.56" y1="73.66" x2="35.56" y2="66.04" width="0.1524" layer="91"/>
<pinref part="IC1" gate="G$1" pin="QE"/>
<wire x1="35.56" y1="66.04" x2="25.4" y2="66.04" width="0.1524" layer="91"/>
</segment>
</net>
<net name="GND" class="0">
<segment>
<pinref part="IC1" gate="G$1" pin="GND"/>
<wire x1="25.4" y1="76.2" x2="27.94" y2="76.2" width="0.1524" layer="91"/>
<wire x1="27.94" y1="76.2" x2="27.94" y2="88.9" width="0.1524" layer="91"/>
<wire x1="27.94" y1="88.9" x2="20.32" y2="88.9" width="0.1524" layer="91"/>
<pinref part="GND1" gate="1" pin="GND"/>
<wire x1="20.32" y1="88.9" x2="20.32" y2="86.36" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="IN" gate="-8" pin="S"/>
<wire x1="-20.32" y1="55.88" x2="-17.78" y2="55.88" width="0.1524" layer="91"/>
<pinref part="GND2" gate="1" pin="GND"/>
<wire x1="-17.78" y1="55.88" x2="-17.78" y2="53.34" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$8" class="0">
<segment>
<pinref part="IN" gate="-1" pin="S"/>
<pinref part="IC1" gate="G$1" pin="!SCLR"/>
<wire x1="-20.32" y1="73.66" x2="-2.54" y2="73.66" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$9" class="0">
<segment>
<pinref part="IN" gate="-2" pin="S"/>
<pinref part="IC1" gate="G$1" pin="SCK"/>
<wire x1="-20.32" y1="71.12" x2="-2.54" y2="71.12" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$10" class="0">
<segment>
<pinref part="IN" gate="-3" pin="S"/>
<pinref part="IC1" gate="G$1" pin="RCK"/>
<wire x1="-20.32" y1="68.58" x2="-2.54" y2="68.58" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$11" class="0">
<segment>
<pinref part="IN" gate="-4" pin="S"/>
<pinref part="IC1" gate="G$1" pin="!G"/>
<wire x1="-20.32" y1="66.04" x2="-2.54" y2="66.04" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$12" class="0">
<segment>
<pinref part="IN" gate="-5" pin="S"/>
<pinref part="IC1" gate="G$1" pin="SI"/>
<wire x1="-20.32" y1="63.5" x2="-2.54" y2="63.5" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$1" class="0">
<segment>
<wire x1="38.1" y1="40.64" x2="38.1" y2="50.8" width="0.1524" layer="91"/>
<pinref part="Q1" gate="G$1" pin="S"/>
<wire x1="38.1" y1="50.8" x2="38.1" y2="60.96" width="0.1524" layer="91"/>
<wire x1="38.1" y1="60.96" x2="38.1" y2="71.12" width="0.1524" layer="91"/>
<wire x1="38.1" y1="71.12" x2="38.1" y2="81.28" width="0.1524" layer="91"/>
<wire x1="38.1" y1="81.28" x2="38.1" y2="91.44" width="0.1524" layer="91"/>
<wire x1="38.1" y1="91.44" x2="43.18" y2="91.44" width="0.1524" layer="91"/>
<pinref part="Q2" gate="G$1" pin="S"/>
<wire x1="43.18" y1="81.28" x2="38.1" y2="81.28" width="0.1524" layer="91"/>
<junction x="38.1" y="81.28"/>
<pinref part="Q3" gate="G$1" pin="S"/>
<wire x1="43.18" y1="71.12" x2="38.1" y2="71.12" width="0.1524" layer="91"/>
<junction x="38.1" y="71.12"/>
<pinref part="Q4" gate="G$1" pin="S"/>
<wire x1="43.18" y1="60.96" x2="38.1" y2="60.96" width="0.1524" layer="91"/>
<junction x="38.1" y="60.96"/>
<pinref part="Q5" gate="G$1" pin="S"/>
<wire x1="43.18" y1="50.8" x2="38.1" y2="50.8" width="0.1524" layer="91"/>
<junction x="38.1" y="50.8"/>
<pinref part="Q6" gate="G$1" pin="S"/>
<wire x1="43.18" y1="40.64" x2="38.1" y2="40.64" width="0.1524" layer="91"/>
<wire x1="-12.7" y1="40.64" x2="38.1" y2="40.64" width="0.1524" layer="91"/>
<junction x="38.1" y="40.64"/>
<pinref part="IN" gate="-7" pin="S"/>
<wire x1="-20.32" y1="58.42" x2="-12.7" y2="58.42" width="0.1524" layer="91"/>
<wire x1="-12.7" y1="58.42" x2="-12.7" y2="40.64" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$13" class="0">
<segment>
<pinref part="IC1" gate="G$1" pin="VCC"/>
<wire x1="-2.54" y1="58.42" x2="-5.08" y2="58.42" width="0.1524" layer="91"/>
<wire x1="-7.62" y1="58.42" x2="-5.08" y2="58.42" width="0.1524" layer="91"/>
<wire x1="-7.62" y1="58.42" x2="-7.62" y2="60.96" width="0.1524" layer="91"/>
<wire x1="-7.62" y1="60.96" x2="-7.62" y2="121.92" width="0.1524" layer="91"/>
<wire x1="-7.62" y1="121.92" x2="66.04" y2="121.92" width="0.1524" layer="91"/>
<pinref part="R1" gate="G$1" pin="2"/>
<wire x1="66.04" y1="121.92" x2="66.04" y2="119.38" width="0.1524" layer="91"/>
<wire x1="66.04" y1="121.92" x2="71.12" y2="121.92" width="0.1524" layer="91"/>
<junction x="66.04" y="121.92"/>
<pinref part="R2" gate="G$1" pin="2"/>
<wire x1="71.12" y1="121.92" x2="71.12" y2="119.38" width="0.1524" layer="91"/>
<wire x1="71.12" y1="121.92" x2="76.2" y2="121.92" width="0.1524" layer="91"/>
<junction x="71.12" y="121.92"/>
<pinref part="R3" gate="G$1" pin="2"/>
<wire x1="76.2" y1="121.92" x2="76.2" y2="119.38" width="0.1524" layer="91"/>
<wire x1="76.2" y1="121.92" x2="81.28" y2="121.92" width="0.1524" layer="91"/>
<junction x="76.2" y="121.92"/>
<pinref part="R4" gate="G$1" pin="2"/>
<wire x1="81.28" y1="121.92" x2="81.28" y2="119.38" width="0.1524" layer="91"/>
<wire x1="81.28" y1="121.92" x2="86.36" y2="121.92" width="0.1524" layer="91"/>
<junction x="81.28" y="121.92"/>
<pinref part="R5" gate="G$1" pin="2"/>
<wire x1="86.36" y1="121.92" x2="86.36" y2="119.38" width="0.1524" layer="91"/>
<wire x1="86.36" y1="121.92" x2="91.44" y2="121.92" width="0.1524" layer="91"/>
<junction x="86.36" y="121.92"/>
<pinref part="R6" gate="G$1" pin="2"/>
<wire x1="91.44" y1="121.92" x2="91.44" y2="119.38" width="0.1524" layer="91"/>
<pinref part="IN" gate="-6" pin="S"/>
<wire x1="-20.32" y1="60.96" x2="-7.62" y2="60.96" width="0.1524" layer="91"/>
<junction x="-7.62" y="60.96"/>
</segment>
</net>
<net name="N$14" class="0">
<segment>
<pinref part="R1" gate="G$1" pin="1"/>
<wire x1="66.04" y1="101.6" x2="66.04" y2="93.98" width="0.1524" layer="91"/>
<pinref part="Q1" gate="G$1" pin="D"/>
<wire x1="66.04" y1="93.98" x2="63.5" y2="93.98" width="0.1524" layer="91"/>
<wire x1="66.04" y1="93.98" x2="96.52" y2="93.98" width="0.1524" layer="91"/>
<junction x="66.04" y="93.98"/>
<wire x1="96.52" y1="93.98" x2="96.52" y2="78.74" width="0.1524" layer="91"/>
<pinref part="OUT" gate="-1" pin="S"/>
<wire x1="96.52" y1="78.74" x2="101.6" y2="78.74" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$15" class="0">
<segment>
<pinref part="R2" gate="G$1" pin="1"/>
<wire x1="71.12" y1="101.6" x2="71.12" y2="83.82" width="0.1524" layer="91"/>
<pinref part="Q2" gate="G$1" pin="D"/>
<wire x1="71.12" y1="83.82" x2="63.5" y2="83.82" width="0.1524" layer="91"/>
<wire x1="71.12" y1="83.82" x2="93.98" y2="83.82" width="0.1524" layer="91"/>
<junction x="71.12" y="83.82"/>
<wire x1="93.98" y1="83.82" x2="93.98" y2="76.2" width="0.1524" layer="91"/>
<pinref part="OUT" gate="-2" pin="S"/>
<wire x1="93.98" y1="76.2" x2="101.6" y2="76.2" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$16" class="0">
<segment>
<pinref part="R3" gate="G$1" pin="1"/>
<wire x1="76.2" y1="101.6" x2="76.2" y2="73.66" width="0.1524" layer="91"/>
<pinref part="Q3" gate="G$1" pin="D"/>
<wire x1="76.2" y1="73.66" x2="63.5" y2="73.66" width="0.1524" layer="91"/>
<pinref part="OUT" gate="-3" pin="S"/>
<wire x1="76.2" y1="73.66" x2="101.6" y2="73.66" width="0.1524" layer="91"/>
<junction x="76.2" y="73.66"/>
</segment>
</net>
<net name="N$17" class="0">
<segment>
<pinref part="R4" gate="G$1" pin="1"/>
<wire x1="81.28" y1="101.6" x2="81.28" y2="63.5" width="0.1524" layer="91"/>
<pinref part="Q4" gate="G$1" pin="D"/>
<wire x1="81.28" y1="63.5" x2="63.5" y2="63.5" width="0.1524" layer="91"/>
<wire x1="81.28" y1="63.5" x2="93.98" y2="63.5" width="0.1524" layer="91"/>
<junction x="81.28" y="63.5"/>
<wire x1="93.98" y1="63.5" x2="93.98" y2="71.12" width="0.1524" layer="91"/>
<pinref part="OUT" gate="-4" pin="S"/>
<wire x1="93.98" y1="71.12" x2="101.6" y2="71.12" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$18" class="0">
<segment>
<pinref part="R5" gate="G$1" pin="1"/>
<wire x1="86.36" y1="101.6" x2="86.36" y2="53.34" width="0.1524" layer="91"/>
<pinref part="Q5" gate="G$1" pin="D"/>
<wire x1="86.36" y1="53.34" x2="63.5" y2="53.34" width="0.1524" layer="91"/>
<wire x1="86.36" y1="53.34" x2="96.52" y2="53.34" width="0.1524" layer="91"/>
<junction x="86.36" y="53.34"/>
<wire x1="96.52" y1="53.34" x2="96.52" y2="68.58" width="0.1524" layer="91"/>
<pinref part="OUT" gate="-5" pin="S"/>
<wire x1="96.52" y1="68.58" x2="101.6" y2="68.58" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$19" class="0">
<segment>
<pinref part="R6" gate="G$1" pin="1"/>
<wire x1="91.44" y1="101.6" x2="91.44" y2="43.18" width="0.1524" layer="91"/>
<pinref part="Q6" gate="G$1" pin="D"/>
<wire x1="91.44" y1="43.18" x2="63.5" y2="43.18" width="0.1524" layer="91"/>
<wire x1="91.44" y1="43.18" x2="99.06" y2="43.18" width="0.1524" layer="91"/>
<junction x="91.44" y="43.18"/>
<wire x1="99.06" y1="43.18" x2="99.06" y2="66.04" width="0.1524" layer="91"/>
<pinref part="OUT" gate="-6" pin="S"/>
<wire x1="99.06" y1="66.04" x2="101.6" y2="66.04" width="0.1524" layer="91"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
<compatibility>
<note version="8.2" severity="warning">
Since Version 8.2, EAGLE supports online libraries. The ids
of those online libraries will not be understood (or retained)
with this version.
</note>
<note version="8.3" severity="warning">
Since Version 8.3, EAGLE supports URNs for individual library
assets (packages, symbols, and devices). The URNs of those assets
will not be understood (or retained) with this version.
</note>
</compatibility>
</eagle>
