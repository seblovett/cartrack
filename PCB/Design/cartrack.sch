<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="6.5.0">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="no" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
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
<library name="quectelm10">
<description>Quectel M10 GSM module</description>
<packages>
<package name="QUECTELM10">
<description>Quectel M10 GSM module by RobotSzoft Kft</description>
<wire x1="-13.97" y1="14.605" x2="15.24" y2="14.605" width="0.127" layer="51"/>
<wire x1="15.24" y1="14.605" x2="15.24" y2="-14.605" width="0.127" layer="51"/>
<wire x1="15.24" y1="-14.605" x2="-13.97" y2="-14.605" width="0.127" layer="51"/>
<wire x1="-13.97" y1="-14.605" x2="-13.97" y2="14.605" width="0.127" layer="51"/>
<circle x="10.5" y="5.51" radius="2.5" width="0.127" layer="18"/>
<smd name="DISP_DATA" x="-13.9" y="12.65" dx="2.2" dy="0.9" layer="1"/>
<smd name="DISP_CLK" x="-13.9" y="11.35" dx="2.2" dy="0.9" layer="1"/>
<smd name="DISP_CS" x="-13.9" y="10.05" dx="2.2" dy="0.9" layer="1"/>
<smd name="DISP_D/C" x="-13.9" y="8.75" dx="2.2" dy="0.9" layer="1"/>
<smd name="DISP_RST" x="-13.9" y="7.45" dx="2.2" dy="0.9" layer="1"/>
<smd name="NETLIGHT" x="-13.9" y="6.15" dx="2.2" dy="0.9" layer="1"/>
<smd name="VDD_EXT" x="-13.9" y="4.85" dx="2.2" dy="0.9" layer="1"/>
<smd name="GND1" x="-13.9" y="-2.15" dx="2.2" dy="0.9" layer="1"/>
<smd name="DBG_RXD" x="-13.9" y="-3.45" dx="2.2" dy="0.9" layer="1"/>
<smd name="DBG_TXD" x="-13.9" y="-4.75" dx="2.2" dy="0.9" layer="1"/>
<smd name="SIM_PRESENCE" x="-13.9" y="-6.05" dx="2.2" dy="0.9" layer="1"/>
<smd name="SIM_VDD" x="-13.9" y="-7.35" dx="2.2" dy="0.9" layer="1"/>
<smd name="SIM_DATA" x="-13.9" y="-8.65" dx="2.2" dy="0.9" layer="1"/>
<smd name="SIM_CLK" x="-13.9" y="-9.95" dx="2.2" dy="0.9" layer="1"/>
<smd name="SIM_RST" x="-13.9" y="-11.25" dx="2.2" dy="0.9" layer="1"/>
<smd name="VRTC" x="-13.9" y="-12.55" dx="2.2" dy="0.9" layer="1"/>
<smd name="EMERG_OFF" x="-9.15" y="-14.45" dx="2.2" dy="0.9" layer="1" rot="R270"/>
<smd name="GPIO0" x="-9.15" y="14.55" dx="2.2" dy="0.9" layer="1" rot="R270"/>
<smd name="GND7" x="15.1" y="12.65" dx="2.2" dy="0.9" layer="1"/>
<smd name="GND6" x="15.1" y="11.35" dx="2.2" dy="0.9" layer="1"/>
<smd name="GND5" x="15.1" y="10.05" dx="2.2" dy="0.9" layer="1"/>
<smd name="GND4" x="15.1" y="8.75" dx="2.2" dy="0.9" layer="1"/>
<smd name="GND3" x="15.1" y="7.45" dx="2.2" dy="0.9" layer="1"/>
<smd name="RF_ANT" x="15.1" y="6.15" dx="2.2" dy="0.9" layer="1"/>
<smd name="GND2" x="15.1" y="4.85" dx="2.2" dy="0.9" layer="1"/>
<smd name="ADC0" x="15.1" y="-2.15" dx="2.2" dy="0.9" layer="1"/>
<smd name="TEMP_BAT" x="15.1" y="-3.45" dx="2.2" dy="0.9" layer="1"/>
<smd name="BUZZER" x="15.1" y="-4.75" dx="2.2" dy="0.9" layer="1"/>
<smd name="GPIO1_KBC5" x="15.1" y="-6.05" dx="2.2" dy="0.9" layer="1"/>
<smd name="KBC4" x="15.1" y="-7.35" dx="2.2" dy="0.9" layer="1"/>
<smd name="KBC3" x="15.1" y="-8.65" dx="2.2" dy="0.9" layer="1"/>
<smd name="KBC2" x="15.1" y="-9.95" dx="2.2" dy="0.9" layer="1"/>
<smd name="KBC1" x="15.1" y="-11.25" dx="2.2" dy="0.9" layer="1"/>
<smd name="KBC0" x="15.1" y="-12.55" dx="2.2" dy="0.9" layer="1"/>
<smd name="RXD3" x="-7.85" y="14.55" dx="2.2" dy="0.9" layer="1" rot="R270"/>
<smd name="TXD3" x="-6.55" y="14.55" dx="2.2" dy="0.9" layer="1" rot="R270"/>
<smd name="RXD" x="-5.25" y="14.55" dx="2.2" dy="0.9" layer="1" rot="R270"/>
<smd name="TXD" x="-3.95" y="14.55" dx="2.2" dy="0.9" layer="1" rot="R270"/>
<smd name="DTR" x="-2.65" y="14.55" dx="2.2" dy="0.9" layer="1" rot="R270"/>
<smd name="RTS" x="-1.35" y="14.55" dx="2.2" dy="0.9" layer="1" rot="R270"/>
<smd name="CTS" x="-0.05" y="14.55" dx="2.2" dy="0.9" layer="1" rot="R270"/>
<smd name="DCD" x="1.25" y="14.55" dx="2.2" dy="0.9" layer="1" rot="R270"/>
<smd name="RI" x="2.55" y="14.55" dx="2.2" dy="0.9" layer="1" rot="R270"/>
<smd name="STATUS" x="3.85" y="14.55" dx="2.2" dy="0.9" layer="1" rot="R270"/>
<smd name="VCHG" x="5.15" y="14.55" dx="2.2" dy="0.9" layer="1" rot="R270"/>
<smd name="VBAT3" x="6.45" y="14.55" dx="2.2" dy="0.9" layer="1" rot="R270"/>
<smd name="VBAT2" x="7.75" y="14.55" dx="2.2" dy="0.9" layer="1" rot="R270"/>
<smd name="VBAT1" x="9.05" y="14.55" dx="2.2" dy="0.9" layer="1" rot="R270"/>
<smd name="GND8" x="10.35" y="14.55" dx="2.2" dy="0.9" layer="1" rot="R270"/>
<smd name="PWRKEY" x="-7.85" y="-14.45" dx="2.2" dy="0.9" layer="1" rot="R270"/>
<smd name="AGND" x="-6.55" y="-14.45" dx="2.2" dy="0.9" layer="1" rot="R270"/>
<smd name="SPK2P" x="-5.25" y="-14.45" dx="2.2" dy="0.9" layer="1" rot="R270"/>
<smd name="SPK1N" x="-3.95" y="-14.45" dx="2.2" dy="0.9" layer="1" rot="R270"/>
<smd name="SPK1P" x="-2.65" y="-14.45" dx="2.2" dy="0.9" layer="1" rot="R270"/>
<smd name="MIC1P" x="-1.35" y="-14.45" dx="2.2" dy="0.9" layer="1" rot="R270"/>
<smd name="MIC1N" x="-0.05" y="-14.45" dx="2.2" dy="0.9" layer="1" rot="R270"/>
<smd name="MIC2P" x="1.25" y="-14.45" dx="2.2" dy="0.9" layer="1" rot="R270"/>
<smd name="MIC2N" x="2.55" y="-14.45" dx="2.2" dy="0.9" layer="1" rot="R270"/>
<smd name="LIGHT_MOS" x="3.85" y="-14.45" dx="2.2" dy="0.9" layer="1" rot="R270"/>
<smd name="KBR0" x="5.15" y="-14.45" dx="2.2" dy="0.9" layer="1" rot="R270"/>
<smd name="KBR1" x="6.45" y="-14.45" dx="2.2" dy="0.9" layer="1" rot="R270"/>
<smd name="KBR2" x="7.75" y="-14.45" dx="2.2" dy="0.9" layer="1" rot="R270"/>
<smd name="KBR4" x="10.35" y="-14.45" dx="2.2" dy="0.9" layer="1" rot="R270"/>
<smd name="KBR3" x="9.05" y="-14.45" dx="2.2" dy="0.9" layer="1" rot="R270"/>
</package>
</packages>
<symbols>
<symbol name="QUECTELM10">
<wire x1="-22.86" y1="-38.1" x2="-22.86" y2="45.72" width="0.254" layer="94"/>
<wire x1="-22.86" y1="45.72" x2="22.86" y2="45.72" width="0.254" layer="94"/>
<wire x1="22.86" y1="45.72" x2="22.86" y2="-38.1" width="0.254" layer="94"/>
<wire x1="22.86" y1="-38.1" x2="-22.86" y2="-38.1" width="0.254" layer="94"/>
<text x="-22.86" y="48.26" size="1.778" layer="95">QUECTEL M10</text>
<text x="-20.32" y="-43.18" size="1.778" layer="96">GSM MODULE</text>
<pin name="DISP_DATA" x="-27.94" y="43.18" length="middle"/>
<pin name="DISP_CLK" x="-27.94" y="40.64" length="middle" direction="out"/>
<pin name="DISP_CS" x="-27.94" y="38.1" length="middle" direction="out"/>
<pin name="DISP_D/C" x="-27.94" y="35.56" length="middle" direction="out"/>
<pin name="DISP_RST" x="-27.94" y="33.02" length="middle" direction="out"/>
<pin name="NETLIGHT" x="-27.94" y="30.48" length="middle" direction="out"/>
<pin name="VDD_EXT" x="-27.94" y="27.94" length="middle" direction="out"/>
<pin name="GND1" x="-27.94" y="25.4" length="middle" direction="sup"/>
<pin name="DBG_RXD" x="-27.94" y="22.86" length="middle" direction="in"/>
<pin name="DBG_TXD" x="-27.94" y="20.32" length="middle" direction="out"/>
<pin name="SIM_PRESENCE" x="-27.94" y="17.78" length="middle" direction="in"/>
<pin name="SIM_VDD" x="-27.94" y="15.24" length="middle" direction="out"/>
<pin name="SIM_DATA" x="-27.94" y="12.7" length="middle"/>
<pin name="SIM_CLK" x="-27.94" y="10.16" length="middle" direction="out"/>
<pin name="SIM_RST" x="-27.94" y="7.62" length="middle" direction="out"/>
<pin name="VRTC" x="-27.94" y="5.08" length="middle"/>
<pin name="EMERG_OFF" x="-27.94" y="2.54" length="middle" direction="in"/>
<pin name="PWRKEY" x="-27.94" y="0" length="middle" direction="in"/>
<pin name="AGND" x="-27.94" y="-2.54" length="middle" direction="out"/>
<pin name="SPK2P" x="-27.94" y="-5.08" length="middle" direction="out"/>
<pin name="SPK1N" x="-27.94" y="-7.62" length="middle" direction="out"/>
<pin name="SPK1P" x="-27.94" y="-10.16" length="middle" direction="out"/>
<pin name="MIC1P" x="-27.94" y="-12.7" length="middle" direction="in"/>
<pin name="MIC1N" x="-27.94" y="-15.24" length="middle" direction="in"/>
<pin name="MIC2P" x="-27.94" y="-17.78" length="middle" direction="in"/>
<pin name="MIC2N" x="-27.94" y="-20.32" length="middle" direction="in"/>
<pin name="LIGHT_MOS" x="-27.94" y="-22.86" length="middle" direction="out"/>
<pin name="KBR0" x="-27.94" y="-25.4" length="middle" direction="out"/>
<pin name="KBR1" x="-27.94" y="-27.94" length="middle" direction="out"/>
<pin name="KBR2" x="-27.94" y="-30.48" length="middle" direction="out"/>
<pin name="KBR3" x="-27.94" y="-33.02" length="middle" direction="out"/>
<pin name="KBR4" x="-27.94" y="-35.56" length="middle" direction="out"/>
<pin name="KBC0" x="27.94" y="-35.56" length="middle" direction="in" rot="R180"/>
<pin name="KBC1" x="27.94" y="-33.02" length="middle" direction="in" rot="R180"/>
<pin name="KBC2" x="27.94" y="-30.48" length="middle" direction="in" rot="R180"/>
<pin name="KBC3" x="27.94" y="-27.94" length="middle" direction="in" rot="R180"/>
<pin name="KBC4" x="27.94" y="-25.4" length="middle" direction="in" rot="R180"/>
<pin name="GPIO1_KBC5" x="27.94" y="-22.86" length="middle" rot="R180"/>
<pin name="BUZZER" x="27.94" y="-20.32" length="middle" direction="out" rot="R180"/>
<pin name="TEMP_BAT" x="27.94" y="-17.78" length="middle" direction="in" rot="R180"/>
<pin name="ADC0" x="27.94" y="-15.24" length="middle" direction="in" rot="R180"/>
<pin name="GND2" x="27.94" y="-12.7" length="middle" direction="sup" rot="R180"/>
<pin name="RF_ANT" x="27.94" y="-10.16" length="middle" rot="R180"/>
<pin name="GND3" x="27.94" y="-7.62" length="middle" direction="sup" rot="R180"/>
<pin name="GND4" x="27.94" y="-5.08" length="middle" direction="sup" rot="R180"/>
<pin name="GND5" x="27.94" y="-2.54" length="middle" rot="R180"/>
<pin name="GND6" x="27.94" y="0" length="middle" direction="sup" rot="R180"/>
<pin name="GND7" x="27.94" y="2.54" length="middle" direction="sup" rot="R180"/>
<pin name="GND8" x="27.94" y="5.08" length="middle" direction="sup" rot="R180"/>
<pin name="VBAT1" x="27.94" y="7.62" length="middle" direction="in" rot="R180"/>
<pin name="VBAT2" x="27.94" y="10.16" length="middle" direction="in" rot="R180"/>
<pin name="VBAT3" x="27.94" y="12.7" length="middle" direction="in" rot="R180"/>
<pin name="VCHG" x="27.94" y="15.24" length="middle" direction="in" rot="R180"/>
<pin name="STATUS" x="27.94" y="17.78" length="middle" direction="out" rot="R180"/>
<pin name="RI" x="27.94" y="20.32" length="middle" direction="out" rot="R180"/>
<pin name="DCD" x="27.94" y="22.86" length="middle" direction="out" rot="R180"/>
<pin name="CTS" x="27.94" y="25.4" length="middle" direction="out" rot="R180"/>
<pin name="RTS" x="27.94" y="27.94" length="middle" direction="in" rot="R180"/>
<pin name="DTR" x="27.94" y="30.48" length="middle" direction="in" rot="R180"/>
<pin name="TXD" x="27.94" y="33.02" length="middle" direction="out" rot="R180"/>
<pin name="RXD" x="27.94" y="35.56" length="middle" direction="in" rot="R180"/>
<pin name="TXD3" x="27.94" y="38.1" length="middle" direction="out" rot="R180"/>
<pin name="RXD3" x="27.94" y="40.64" length="middle" direction="in" rot="R180"/>
<pin name="GPIO0" x="27.94" y="43.18" length="middle" rot="R180"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="QUECTELM10">
<description>Quectel M10 GSM module by RobotSzoft Kft</description>
<gates>
<gate name="G$1" symbol="QUECTELM10" x="0" y="-2.54"/>
</gates>
<devices>
<device name="" package="QUECTELM10">
<connects>
<connect gate="G$1" pin="ADC0" pad="ADC0"/>
<connect gate="G$1" pin="AGND" pad="AGND"/>
<connect gate="G$1" pin="BUZZER" pad="BUZZER"/>
<connect gate="G$1" pin="CTS" pad="CTS"/>
<connect gate="G$1" pin="DBG_RXD" pad="DBG_RXD"/>
<connect gate="G$1" pin="DBG_TXD" pad="DBG_TXD"/>
<connect gate="G$1" pin="DCD" pad="DCD"/>
<connect gate="G$1" pin="DISP_CLK" pad="DISP_CLK"/>
<connect gate="G$1" pin="DISP_CS" pad="DISP_CS"/>
<connect gate="G$1" pin="DISP_D/C" pad="DISP_D/C"/>
<connect gate="G$1" pin="DISP_DATA" pad="DISP_DATA"/>
<connect gate="G$1" pin="DISP_RST" pad="DISP_RST"/>
<connect gate="G$1" pin="DTR" pad="DTR"/>
<connect gate="G$1" pin="EMERG_OFF" pad="EMERG_OFF"/>
<connect gate="G$1" pin="GND1" pad="GND1"/>
<connect gate="G$1" pin="GND2" pad="GND2"/>
<connect gate="G$1" pin="GND3" pad="GND3"/>
<connect gate="G$1" pin="GND4" pad="GND4"/>
<connect gate="G$1" pin="GND5" pad="GND5"/>
<connect gate="G$1" pin="GND6" pad="GND6"/>
<connect gate="G$1" pin="GND7" pad="GND7"/>
<connect gate="G$1" pin="GND8" pad="GND8"/>
<connect gate="G$1" pin="GPIO0" pad="GPIO0"/>
<connect gate="G$1" pin="GPIO1_KBC5" pad="GPIO1_KBC5"/>
<connect gate="G$1" pin="KBC0" pad="KBC0"/>
<connect gate="G$1" pin="KBC1" pad="KBC1"/>
<connect gate="G$1" pin="KBC2" pad="KBC2"/>
<connect gate="G$1" pin="KBC3" pad="KBC3"/>
<connect gate="G$1" pin="KBC4" pad="KBC4"/>
<connect gate="G$1" pin="KBR0" pad="KBR0"/>
<connect gate="G$1" pin="KBR1" pad="KBR1"/>
<connect gate="G$1" pin="KBR2" pad="KBR2"/>
<connect gate="G$1" pin="KBR3" pad="KBR3"/>
<connect gate="G$1" pin="KBR4" pad="KBR4"/>
<connect gate="G$1" pin="LIGHT_MOS" pad="LIGHT_MOS"/>
<connect gate="G$1" pin="MIC1N" pad="MIC1N"/>
<connect gate="G$1" pin="MIC1P" pad="MIC1P"/>
<connect gate="G$1" pin="MIC2N" pad="MIC2N"/>
<connect gate="G$1" pin="MIC2P" pad="MIC2P"/>
<connect gate="G$1" pin="NETLIGHT" pad="NETLIGHT"/>
<connect gate="G$1" pin="PWRKEY" pad="PWRKEY"/>
<connect gate="G$1" pin="RF_ANT" pad="RF_ANT"/>
<connect gate="G$1" pin="RI" pad="RI"/>
<connect gate="G$1" pin="RTS" pad="RTS"/>
<connect gate="G$1" pin="RXD" pad="RXD"/>
<connect gate="G$1" pin="RXD3" pad="RXD3"/>
<connect gate="G$1" pin="SIM_CLK" pad="SIM_CLK"/>
<connect gate="G$1" pin="SIM_DATA" pad="SIM_DATA"/>
<connect gate="G$1" pin="SIM_PRESENCE" pad="SIM_PRESENCE"/>
<connect gate="G$1" pin="SIM_RST" pad="SIM_RST"/>
<connect gate="G$1" pin="SIM_VDD" pad="SIM_VDD"/>
<connect gate="G$1" pin="SPK1N" pad="SPK1N"/>
<connect gate="G$1" pin="SPK1P" pad="SPK1P"/>
<connect gate="G$1" pin="SPK2P" pad="SPK2P"/>
<connect gate="G$1" pin="STATUS" pad="STATUS"/>
<connect gate="G$1" pin="TEMP_BAT" pad="TEMP_BAT"/>
<connect gate="G$1" pin="TXD" pad="TXD"/>
<connect gate="G$1" pin="TXD3" pad="TXD3"/>
<connect gate="G$1" pin="VBAT1" pad="VBAT1"/>
<connect gate="G$1" pin="VBAT2" pad="VBAT2"/>
<connect gate="G$1" pin="VBAT3" pad="VBAT3"/>
<connect gate="G$1" pin="VCHG" pad="VCHG"/>
<connect gate="G$1" pin="VDD_EXT" pad="VDD_EXT"/>
<connect gate="G$1" pin="VRTC" pad="VRTC"/>
</connects>
<technologies>
<technology name=""/>
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
<part name="U$1" library="quectelm10" deviceset="QUECTELM10" device=""/>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
<instance part="U$1" gate="G$1" x="48.26" y="40.64"/>
</instances>
<busses>
</busses>
<nets>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
</eagle>
