/* Ghidra analysis pseudocode, not original source.
 * ev_966db37b3c76367cdd19664fe0d1b84c77d56b151d5f2c268a183ca8a07fabfc
 * Entry: 0x48da50; label: FUN_0048da50
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0048da50(undefined4 param_1)

{
  undefined2 uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  FUN_00578e10(param_1);
  DAT_00951b88 = FUN_00578da0("titles",0);
  if (DAT_00951b88 != 0) {
    *(code **)(DAT_00951b88 + 0x6c) = FUN_00489b60;
    *(code **)(DAT_00951b88 + 0x74) = FUN_00489ca0;
    *(code **)(DAT_00951b88 + 0x7c) = FUN_00489da0;
    *(uint *)(DAT_00951b88 + 100) = *(uint *)(DAT_00951b88 + 100) & 0xfffffff5;
    uVar1 = FUN_00548a60("titles",DAT_009248cc,0xffffffff);
    *(undefined2 *)(DAT_00951b88 + 0x94) = uVar1;
    uVar2 = FUN_00694320(1,"titles");
    *(undefined4 *)(DAT_00951b88 + 0x11c) = uVar2;
    *(undefined4 *)(DAT_00951b88 + 0x118) = *(undefined4 *)(DAT_00951b88 + 0x11c);
    uVar2 = FUN_00694320(2,"titles");
    *(undefined4 *)(DAT_00951b88 + 0x124) = uVar2;
    *(undefined4 *)(DAT_00951b88 + 0x120) = *(undefined4 *)(DAT_00951b88 + 0x124);
    uVar2 = FUN_00694320(0x20,"titles");
    *(undefined4 *)(DAT_00951b88 + 300) = uVar2;
    *(undefined4 *)(DAT_00951b88 + 0x128) = *(undefined4 *)(DAT_00951b88 + 300);
  }
  DAT_00951b98 = FUN_00578da0("status",0);
  if (DAT_00951b98 != 0) {
    *(code **)(DAT_00951b98 + 0x74) = FUN_00486c60;
    *(undefined1 **)(DAT_00951b98 + 0x80) = &LAB_00486200;
    *(uint *)(DAT_00951b98 + 100) = *(uint *)(DAT_00951b98 + 100) | 0x400;
    *(uint *)(DAT_00951b98 + 100) = *(uint *)(DAT_00951b98 + 100) & 0xfffffff5;
  }
  DAT_00951b9c = FUN_00578da0("credits",0);
  if (DAT_00951b9c != 0) {
    *(undefined4 *)(DAT_00951b9c + 100) = 0;
    *(undefined1 **)(DAT_00951b9c + 0x68) = &LAB_0059cd50;
    *(undefined1 **)(DAT_00951b9c + 0x6c) = &LAB_0048d6b0;
    *(code **)(DAT_00951b9c + 0x74) = FUN_0048d7d0;
    *(undefined1 **)(DAT_00951b9c + 0x7c) = &LAB_0048d830;
    *(undefined1 **)(DAT_00951b9c + 0x80) = &LAB_0059d450;
  }
  if (DAT_00876580 == 0) {
    if (DAT_007f39e4 == 0) {
      _DAT_0087af38 = FUN_00578da0("batcave_a",0);
      DAT_00951b94 = _DAT_0087af38;
      _DAT_0087af3c = FUN_00578da0("rooftops_a",0);
      DAT_0087af40 = FUN_00578da0("fairgroundbad_a",0);
      if (DAT_0087af40 != 0) {
        *(undefined1 **)(DAT_0087af40 + 0x6c) = &LAB_004ee970;
        *(undefined1 **)(DAT_0087af40 + 0x74) = &LAB_004ee990;
        *(undefined **)(DAT_0087af40 + 0x7c) = &DAT_004eeae0;
      }
    }
    else {
      DAT_0087b2a4 = FUN_00578da0("losttemple_a",0);
      DAT_0087b2a8 = FUN_00578da0("losttemple_c",0);
      if (DAT_0087b2a8 != 0) {
        *(undefined1 **)(DAT_0087b2a8 + 0x70) = &LAB_00481920;
        *(undefined1 **)(DAT_0087b2a8 + 0x74) = &LAB_00481950;
      }
      _DAT_0087b2ac = FUN_00578da0("losttemple_d",0);
      _DAT_0087b2b0 = FUN_00578da0("losttemple_e",0);
      _DAT_0087b2b4 = FUN_00578da0("losttemple_f",0);
      _DAT_0087b2b8 = FUN_00578da0("losttemple_outrowin",0);
      DAT_0087b2bc = FUN_00578da0("losttemple_outrolose",0);
      DAT_00951b94 = FUN_00578da0(&DAT_00759c2c,0);
      if (DAT_00951b94 != 0) {
        *(undefined1 **)(DAT_00951b94 + 0x68) = &LAB_004778d0;
        *(undefined1 **)(DAT_00951b94 + 0x6c) = &LAB_0047cab0;
        *(undefined1 **)(DAT_00951b94 + 0x70) = &LAB_00479b30;
        *(code **)(DAT_00951b94 + 0x74) = FUN_0047cdd0;
        *(undefined1 **)(DAT_00951b94 + 0x7c) = &LAB_00479ed0;
        *(undefined1 **)(DAT_00951b94 + 0x80) = &LAB_0047dce0;
      }
      DAT_0087b234 = FUN_00578da0("speederchase_a",0);
      if (DAT_0087b234 != 0) {
        *(undefined1 **)(DAT_0087b234 + 0x6c) = &LAB_004c8c40;
        *(undefined1 **)(DAT_0087b234 + 0x70) = &LAB_004c8d90;
        *(undefined1 **)(DAT_0087b234 + 0x74) = &LAB_004c8e40;
        *(code **)(DAT_0087b234 + 0x80) = FUN_004c9080;
      }
      DAT_0087b04c = FUN_00578da0("negotiations_a",0);
      DAT_0087b050 = FUN_00578da0("negotiations_b",0);
      DAT_0087b054 = FUN_00578da0("negotiations_c",0);
      DAT_0087b058 = FUN_00578da0("gungan_a",0);
      if (DAT_0087b058 != 0) {
        *(undefined1 **)(DAT_0087b058 + 0x6c) = &LAB_004d82f0;
        *(undefined1 **)(DAT_0087b058 + 0x74) = &LAB_004d83e0;
      }
      DAT_0087b05c = FUN_00578da0("rescue_c",0);
      DAT_0087b060 = FUN_00578da0("PodRace_Arrival1",0);
      DAT_0087b064 = FUN_00578da0("PodRace_Arrival2",0);
      _DAT_0087b068 = FUN_00578da0("PodRace_Arrival3",0);
      _DAT_0087b06c = FUN_00578da0("PodRace_Arrival4",0);
      _DAT_0087b070 = FUN_00578da0("PodRace_Intro",0);
      _DAT_0087b074 = FUN_00578da0("PodRace_B",0);
      _DAT_0087b078 = FUN_00578da0("PodRace_C",0);
      _DAT_0087b07c = FUN_00578da0("PodRace_A",0);
      _DAT_0087b080 = FUN_00578da0("PodRace_Outro1",0);
      _DAT_0087b084 = FUN_00578da0("PodRace_Outro2",0);
      _DAT_0087b088 = FUN_00578da0("PodRace_Status",0);
      DAT_0087b164 = FUN_00578da0("ANewHope_Intro",0);
      DAT_0087b168 = FUN_00578da0("ANewHope_A",0);
      _DAT_0087b16c = FUN_00578da0("ANewHope_B",0);
      _DAT_0087b170 = FUN_00578da0("ANewHope_Status",0);
      DAT_0087b090 = FUN_00578da0("podrace_b",0);
      if (DAT_0087b090 != 0) {
        *(undefined1 **)(DAT_0087b090 + 0x6c) = &LAB_004dd580;
        *(undefined1 **)(DAT_0087b090 + 0x70) = &LAB_004dd5c0;
        *(undefined1 **)(DAT_0087b090 + 0x74) = &LAB_004dae30;
        *(undefined1 **)(DAT_0087b090 + 0x78) = &LAB_004daa50;
        *(undefined1 **)(DAT_0087b090 + 0x80) = &LAB_004da3b0;
      }
      DAT_0087b08c = FUN_00578da0("podrace_a",0);
      if (DAT_0087b08c != 0) {
        *(undefined1 **)(DAT_0087b08c + 0x6c) = &LAB_004dd4e0;
        *(undefined1 **)(DAT_0087b08c + 0x70) = &LAB_004dd4f0;
        *(code **)(DAT_0087b08c + 0x74) = FUN_004daab0;
        *(undefined1 **)(DAT_0087b08c + 0x78) = &LAB_004daaf0;
        *(undefined1 **)(DAT_0087b08c + 0x7c) = &LAB_004dab40;
        *(undefined1 **)(DAT_0087b08c + 0x80) = &LAB_004da3b0;
      }
      DAT_0087b094 = FUN_00578da0("podrace_c",0);
      if (DAT_0087b094 != 0) {
        *(undefined1 **)(DAT_0087b094 + 0x6c) = &LAB_004dd650;
        *(undefined1 **)(DAT_0087b094 + 0x70) = &LAB_004dd770;
        *(undefined1 **)(DAT_0087b094 + 0x74) = &LAB_004db080;
        *(undefined1 **)(DAT_0087b094 + 0x78) = &LAB_004daa50;
        *(undefined1 **)(DAT_0087b094 + 0x80) = &LAB_004da3b0;
      }
      DAT_0087b098 = FUN_00578da0("PodRace_Outro1",0);
      DAT_0087b09c = FUN_00578da0("podrace_status",0);
      DAT_0087b0a0 = FUN_00578da0("PodSprint_A",0);
      if (DAT_0087b0a0 != 0) {
        *(undefined1 **)(DAT_0087b0a0 + 0x6c) = &LAB_004dbce0;
        *(undefined1 **)(DAT_0087b0a0 + 0x70) = &LAB_004dbe20;
        *(undefined1 **)(DAT_0087b0a0 + 0x74) = &LAB_004dc640;
        *(undefined1 **)(DAT_0087b0a0 + 0x80) = &LAB_004dc810;
      }
      DAT_0087b0b4 = FUN_00578da0("AnakinsFlight_B",0);
      if (DAT_0087b0b4 != 0) {
        *(code **)(DAT_0087b0b4 + 0x6c) = FUN_004dd2f0;
        *(undefined **)(DAT_0087b0b4 + 0x74) = &DAT_004dd380;
        *(undefined **)(DAT_0087b0b4 + 0x7c) = &DAT_004dd390;
      }
      DAT_0087b0a4 = FUN_00578da0("retake_b",0);
      DAT_0087b0a8 = FUN_00578da0("retake_d",0);
      DAT_0087b0ac = FUN_00578da0("retake_e",0);
      DAT_0087b0b0 = FUN_00578da0("retake_g",0);
      if (DAT_0087b0b0 != 0) {
        *(undefined1 **)(DAT_0087b0b0 + 0x6c) = &LAB_004dceb0;
        *(undefined **)(DAT_0087b0b0 + 0x70) = &DAT_004dcef0;
        *(undefined1 **)(DAT_0087b0b0 + 0x74) = &LAB_004dcf00;
        *(code **)(DAT_0087b0b0 + 0x80) = FUN_004dcf70;
      }
      DAT_0087b0b8 = FUN_00578da0("Maul_A",0);
      if (DAT_0087b0b8 != 0) {
        *(undefined1 **)(DAT_0087b0b8 + 0x6c) = &LAB_004dd070;
        *(code **)(DAT_0087b0b8 + 0x70) = FUN_004dd110;
        *(undefined **)(DAT_0087b0b8 + 0x74) = &DAT_004dd160;
        *(undefined1 **)(DAT_0087b0b8 + 0x80) = &LAB_004dd170;
      }
      _DAT_0087b0bc = FUN_00578da0("Maul_B",0);
      DAT_0087b0c0 = FUN_00578da0("Maul_D",0);
      if (DAT_0087b0c0 != 0) {
        *(undefined **)(DAT_0087b0c0 + 0x6c) = &DAT_004dd1d0;
        *(undefined **)(DAT_0087b0c0 + 0x74) = &DAT_004dd1e0;
      }
      DAT_0087b0c4 = FUN_00578da0("Maul_E",0);
      if (DAT_0087b0c4 != 0) {
        *(undefined **)(DAT_0087b0c4 + 0x6c) = &DAT_004dd1f0;
        *(undefined **)(DAT_0087b0c4 + 0x74) = &DAT_004dd200;
      }
      DAT_0087b0c8 = FUN_00578da0("Maul_F",0);
      if (DAT_0087b0c8 != 0) {
        *(undefined1 **)(DAT_0087b0c8 + 0x6c) = &LAB_004dd210;
        *(undefined1 **)(DAT_0087b0c8 + 0x70) = &LAB_004dd280;
        *(undefined **)(DAT_0087b0c8 + 0x74) = &DAT_004dd2a0;
        *(undefined1 **)(DAT_0087b0c8 + 0x80) = &LAB_004dd2b0;
      }
      DAT_0087b0cc = FUN_00578da0("Jedi_B",0);
      if (DAT_0087b0cc != 0) {
        *(code **)(DAT_0087b0cc + 0x6c) = FUN_004de360;
        *(code **)(DAT_0087b0cc + 0x70) = FUN_004de740;
        *(undefined1 **)(DAT_0087b0cc + 0x74) = &LAB_004df120;
        *(code **)(DAT_0087b0cc + 0x80) = FUN_004df9b0;
      }
      DAT_0087b0d0 = FUN_00578da0("Jedi_Outro",0);
      DAT_0087b0d4 = FUN_00578da0("gunship_a",0);
      if (DAT_0087b0d4 != 0) {
        *(code **)(DAT_0087b0d4 + 0x6c) = FUN_004e23e0;
        *(undefined1 **)(DAT_0087b0d4 + 0x74) = &LAB_004e24d0;
        *(undefined1 **)(DAT_0087b0d4 + 0x7c) = &LAB_004e24e0;
      }
      DAT_0087b0d8 = FUN_00578da0("gunship_b",0);
      if (DAT_0087b0d8 != 0) {
        *(undefined1 **)(DAT_0087b0d8 + 0x70) = &LAB_004e24f0;
      }
      DAT_0087b0dc = FUN_00578da0("bonus_gunship_a",0);
      if (DAT_0087b0dc != 0) {
        *(undefined1 **)(DAT_0087b0dc + 0x70) = &LAB_004e2740;
        *(undefined1 **)(DAT_0087b0dc + 0x74) = &LAB_004e2770;
      }
      DAT_0087b0e0 = FUN_00578da0("bonus_gunship_b",0);
      if (DAT_0087b0e0 != 0) {
        *(undefined1 **)(DAT_0087b0e0 + 0x6c) = &LAB_004e2860;
        *(undefined1 **)(DAT_0087b0e0 + 0x70) = &LAB_004e2890;
        *(undefined1 **)(DAT_0087b0e0 + 0x74) = &LAB_004e28b0;
        *(undefined1 **)(DAT_0087b0e0 + 0x80) = &LAB_004e2ae0;
      }
      DAT_0087b0e4 = FUN_00578da0("pursuit_a",0);
      if (DAT_0087b0e4 != 0) {
        *(undefined **)(DAT_0087b0e4 + 0x6c) = &DAT_004bc4b0;
        *(undefined1 **)(DAT_0087b0e4 + 0x70) = &LAB_004bc4c0;
        *(undefined1 **)(DAT_0087b0e4 + 0x74) = &LAB_004bc4f0;
      }
      DAT_0087b0e8 = FUN_00578da0("pursuit_b",0);
      if (DAT_0087b0e8 != 0) {
        *(undefined **)(DAT_0087b0e8 + 0x6c) = &DAT_004bc500;
        *(undefined1 **)(DAT_0087b0e8 + 0x70) = &LAB_004bc510;
        *(undefined1 **)(DAT_0087b0e8 + 0x74) = &LAB_004bc620;
      }
      DAT_0087b0ec = FUN_00578da0("pursuit_c",0);
      if (DAT_0087b0ec != 0) {
        *(undefined **)(DAT_0087b0ec + 0x6c) = &DAT_004bc640;
        *(undefined1 **)(DAT_0087b0ec + 0x70) = &LAB_004bc650;
        *(code **)(DAT_0087b0ec + 0x74) = FUN_004bc750;
      }
      DAT_0087b0f0 = FUN_00578da0("pursuit_d",0);
      if (DAT_0087b0f0 != 0) {
        *(undefined **)(DAT_0087b0f0 + 0x6c) = &DAT_004bc800;
        *(undefined1 **)(DAT_0087b0f0 + 0x70) = &LAB_004bc810;
        *(undefined1 **)(DAT_0087b0f0 + 0x74) = &LAB_004bc990;
      }
      DAT_0087b0f4 = FUN_00578da0("pursuit_e",0);
      DAT_0087b0f8 = FUN_00578da0("dogfight_a",0);
      if (DAT_0087b0f8 != 0) {
        *(code **)(DAT_0087b0f8 + 0x6c) = FUN_00413a20;
        *(undefined1 **)(DAT_0087b0f8 + 0x70) = &LAB_004124f0;
        *(undefined1 **)(DAT_0087b0f8 + 0x74) = &LAB_00413aa0;
        *(code **)(DAT_0087b0f8 + 0x7c) = FUN_00413b10;
      }
      DAT_0087b0fc = FUN_00578da0("Factory_B",0);
      if (DAT_0087b0fc != 0) {
        *(undefined1 **)(DAT_0087b0fc + 0x6c) = &LAB_004e2c60;
        *(code **)(DAT_0087b0fc + 0x70) = FUN_004dfc90;
        *(code **)(DAT_0087b0fc + 0x74) = FUN_004dfd00;
        *(undefined1 **)(DAT_0087b0fc + 0x7c) = &LAB_004dfdf0;
      }
      DAT_0087b100 = FUN_00578da0("Factory_D",0);
      DAT_0087b104 = FUN_00578da0("Factory_F",0);
      DAT_0087b108 = FUN_00578da0("Factory_G",0);
      if (DAT_0087b108 != 0) {
        *(undefined1 **)(DAT_0087b108 + 0x6c) = &LAB_004dff40;
        *(code **)(DAT_0087b108 + 0x74) = FUN_004dfff0;
      }
      DAT_0087b11c = FUN_00578da0("Dooku_C",0);
      if (DAT_0087b11c != 0) {
        *(undefined1 **)(DAT_0087b11c + 0x70) = &LAB_004dfe00;
        *(undefined1 **)(DAT_0087b11c + 0x74) = &LAB_004dfe80;
        *(undefined1 **)(DAT_0087b11c + 0x80) = &LAB_004dfef0;
      }
      DAT_0087b120 = FUN_00578da0("Dooku_Outro",0);
      DAT_0087b10c = FUN_00578da0("Kamino_A",0);
      if (DAT_0087b10c != 0) {
        *(undefined1 **)(DAT_0087b10c + 0x78) = &LAB_004e0180;
      }
      DAT_0087b110 = FUN_00578da0("Kamino_C",0);
      if (DAT_0087b110 != 0) {
        *(code **)(DAT_0087b110 + 0x70) = FUN_004e06e0;
        *(code **)(DAT_0087b110 + 0x6c) = FUN_004e01b0;
        *(undefined1 **)(DAT_0087b110 + 0x74) = &LAB_004e0b50;
      }
      DAT_0087b118 = FUN_00578da0("Kamino_Outro1",0);
      if (DAT_0087b118 != 0) {
        *(undefined1 **)(DAT_0087b118 + 0x6c) = &LAB_004e23b0;
      }
      DAT_0087b10c = FUN_00578da0("Kamino_A",0);
      DAT_0087b110 = FUN_00578da0("Kamino_C",0);
      DAT_0087b114 = FUN_00578da0("Kamino_E",0);
      if (DAT_0087b114 != 0) {
        *(code **)(DAT_0087b114 + 0x70) = FUN_004e1260;
        *(undefined1 **)(DAT_0087b114 + 0x6c) = &LAB_004e1220;
        *(undefined1 **)(DAT_0087b114 + 0x78) = &LAB_004e1f40;
        *(undefined1 **)(DAT_0087b114 + 0x74) = &LAB_004e1f70;
        *(undefined1 **)(DAT_0087b114 + 0x7c) = &LAB_004e2280;
      }
      DAT_0087b0f8 = FUN_00578da0("Dogfight_A",0);
      DAT_0087b144 = FUN_00578da0("Cruiser_A",0);
      if (DAT_0087b144 != 0) {
        *(code **)(DAT_0087b144 + 0x6c) = FUN_004e2cf0;
        *(undefined1 **)(DAT_0087b144 + 0x74) = &LAB_004e2d50;
      }
      DAT_0087b148 = FUN_00578da0("Cruiser_C",0);
      if (DAT_0087b148 != 0) {
        *(undefined1 **)(DAT_0087b148 + 0x70) = &LAB_004e2db0;
        *(undefined1 **)(DAT_0087b148 + 0x74) = &LAB_004e2de0;
        *(undefined1 **)(DAT_0087b148 + 0x80) = &LAB_004e2f40;
      }
      DAT_0087b14c = FUN_00578da0("Cruiser_D",0);
      if (DAT_0087b14c != 0) {
        *(code **)(DAT_0087b14c + 0x6c) = FUN_004e2f80;
        *(undefined1 **)(DAT_0087b14c + 0x70) = &LAB_004e3040;
        *(undefined1 **)(DAT_0087b14c + 0x74) = &LAB_004e3120;
      }
      DAT_0087b150 = FUN_00578da0("Cruiser_E",0);
      DAT_0087b154 = FUN_00578da0("cruiser_g",0);
      DAT_0087b124 = FUN_00578da0("Grievous_A",0);
      if (DAT_0087b124 != 0) {
        *(undefined **)(DAT_0087b124 + 0x6c) = &DAT_004e3330;
        *(undefined1 **)(DAT_0087b124 + 0x70) = &LAB_004e3340;
        *(undefined1 **)(DAT_0087b124 + 0x74) = &LAB_004e3380;
      }
      DAT_0087b128 = FUN_00578da0("temple_b",0);
      _DAT_0087b12c = FUN_00578da0("temple_c",0);
      if (_DAT_0087b12c != 0) {
        *(code **)(_DAT_0087b12c + 0x78) = FUN_004e3c30;
      }
      DAT_0087b130 = FUN_00578da0("temple_status",0);
      DAT_0087b134 = FUN_00578da0("Kashyyyk_A",0);
      if (DAT_0087b134 != 0) {
        *(undefined **)(DAT_0087b134 + 0x6c) = &DAT_004e33e0;
        *(undefined1 **)(DAT_0087b134 + 0x70) = &LAB_004e33f0;
        *(undefined **)(DAT_0087b134 + 0x74) = &DAT_004e3430;
        *(code **)(DAT_0087b134 + 0x80) = FUN_004e3440;
      }
      DAT_0087b138 = FUN_00578da0("Kashyyyk_B",0);
      if (DAT_0087b138 != 0) {
        *(undefined **)(DAT_0087b138 + 0x6c) = &DAT_004e3540;
        *(undefined **)(DAT_0087b138 + 0x70) = &DAT_004e3550;
        *(undefined **)(DAT_0087b138 + 0x74) = &DAT_004e3560;
      }
      DAT_0087b13c = FUN_00578da0("Kashyyyk_C",0);
      if (DAT_0087b13c != 0) {
        *(undefined **)(DAT_0087b13c + 0x6c) = &DAT_004e3570;
        *(undefined **)(DAT_0087b13c + 0x74) = &DAT_004e3580;
      }
      DAT_0087b140 = FUN_00578da0("Kashyyyk_D",0);
      if (DAT_0087b140 != 0) {
        *(undefined1 **)(DAT_0087b140 + 0x6c) = &LAB_004e3590;
        *(undefined1 **)(DAT_0087b140 + 0x70) = &LAB_004e35d0;
        *(undefined1 **)(DAT_0087b140 + 0x74) = &LAB_004e3990;
      }
      DAT_0087b158 = FUN_00578da0("vader_a",0);
      if (DAT_0087b158 != 0) {
        *(undefined1 **)(DAT_0087b158 + 0x6c) = &LAB_004e3db0;
        *(undefined1 **)(DAT_0087b158 + 0x70) = &LAB_004e3e50;
        *(undefined1 **)(DAT_0087b158 + 0x74) = &LAB_004e3ea0;
        *(undefined1 **)(DAT_0087b158 + 0x80) = &LAB_004e41e0;
      }
      DAT_0087b15c = FUN_00578da0("vader_b",0);
      if (DAT_0087b15c != 0) {
        *(undefined **)(DAT_0087b15c + 0x6c) = &DAT_004e4260;
        *(undefined1 **)(DAT_0087b15c + 0x70) = &LAB_004e4270;
        *(undefined1 **)(DAT_0087b15c + 0x74) = &LAB_004e42a0;
        *(undefined **)(DAT_0087b15c + 0x80) = &DAT_004e4340;
      }
      DAT_0087b160 = FUN_00578da0("vader_c",0);
      if (DAT_0087b160 != 0) {
        *(code **)(DAT_0087b160 + 0x6c) = FUN_004e4350;
        *(undefined1 **)(DAT_0087b160 + 0x70) = &LAB_004e4470;
        *(undefined1 **)(DAT_0087b160 + 0x74) = &LAB_004e4480;
        *(undefined1 **)(DAT_0087b160 + 0x80) = &LAB_004e49c0;
      }
      DAT_0087b174 = FUN_00578da0("BlockadeRunner_B",0);
      if (DAT_0087b174 != 0) {
        *(undefined1 **)(DAT_0087b174 + 0x6c) = &LAB_004e4b40;
        *(undefined1 **)(DAT_0087b174 + 0x74) = &LAB_004e4b60;
      }
      DAT_0087b178 = FUN_00578da0("BlockadeRunner_C",0);
      if (DAT_0087b178 != 0) {
        *(undefined1 **)(DAT_0087b178 + 0x6c) = &LAB_004e4b90;
      }
      DAT_0087b17c = FUN_00578da0("BlockadeRunner_D",0);
      if (DAT_0087b17c != 0) {
        *(undefined1 **)(DAT_0087b17c + 0x70) = &LAB_004e4df0;
        *(undefined1 **)(DAT_0087b17c + 0x74) = &LAB_004e4e40;
      }
      DAT_0087b190 = FUN_00578da0("moseisley_a",0);
      DAT_0087b194 = FUN_00578da0("moseisley_b",0);
      if (DAT_0087b194 != 0) {
        *(code **)(DAT_0087b194 + 0x6c) = FUN_004e4a40;
      }
      DAT_0087b198 = FUN_00578da0("moseisley_c",0);
      DAT_0087b19c = FUN_00578da0("moseisley_d",0);
      if (DAT_0087b19c != 0) {
        *(undefined1 **)(DAT_0087b19c + 0x78) = &LAB_004e4ab0;
      }
      DAT_0087b1a0 = FUN_00578da0("moseisley_e",0);
      if (DAT_0087b1a0 != 0) {
        *(undefined1 **)(DAT_0087b1a0 + 0x6c) = &LAB_004e4ad0;
        *(undefined1 **)(DAT_0087b1a0 + 0x70) = &LAB_004e4b00;
        *(undefined1 **)(DAT_0087b1a0 + 0x74) = &LAB_004e4b10;
      }
      DAT_0087b180 = FUN_00578da0("tatooine_a",0);
      DAT_0087b184 = FUN_00578da0("tatooine_b",0);
      DAT_0087b188 = FUN_00578da0("tatooine_d",0);
      DAT_0087b18c = FUN_00578da0("tatooine_e",0);
      DAT_0087b1a4 = FUN_00578da0("deathstarrescue_a",0);
      DAT_0087b1a8 = FUN_00578da0("deathstarrescue_b",0);
      if (DAT_0087b1a8 != 0) {
        *(code **)(DAT_0087b1a8 + 0x6c) = FUN_004e4f80;
        *(code **)(DAT_0087b1a8 + 0x74) = FUN_004e5060;
        *(undefined1 **)(DAT_0087b1a8 + 0x78) = &LAB_004e5130;
      }
      DAT_0087b1ac = FUN_00578da0("deathstarrescue_c",0);
      if (DAT_0087b1ac != 0) {
        *(undefined1 **)(DAT_0087b1ac + 0x78) = &LAB_004e5150;
      }
      DAT_0087b1b0 = FUN_00578da0("deathstarrescue_d",0);
      DAT_0087b1b4 = FUN_00578da0("deathstarrescue_e",0);
      DAT_0087b1b8 = FUN_00578da0("deathstarescape_a",0);
      if (DAT_0087b1b8 != 0) {
        *(undefined1 **)(DAT_0087b1b8 + 0x74) = &LAB_004e5460;
      }
      DAT_0087b1bc = FUN_00578da0("deathstarescape_b",0);
      if (DAT_0087b1bc != 0) {
        *(undefined1 **)(DAT_0087b1bc + 0x6c) = &LAB_004e5170;
        *(code **)(DAT_0087b1bc + 0x74) = FUN_004e5240;
        *(code **)(DAT_0087b1bc + 0x78) = FUN_004e5380;
        *(undefined1 **)(DAT_0087b1bc + 0x7c) = &LAB_004e53e0;
      }
      DAT_0087b1c0 = FUN_00578da0("deathstarescape_c",0);
      if (DAT_0087b1c0 != 0) {
        *(code **)(DAT_0087b1c0 + 0x6c) = FUN_004e54d0;
        *(undefined1 **)(DAT_0087b1c0 + 0x74) = &LAB_004e5540;
        *(undefined1 **)(DAT_0087b1c0 + 0x70) = &LAB_004e5520;
      }
      DAT_0087b1c4 = FUN_00578da0("deathstarescape_d",0);
      if (DAT_0087b1c4 != 0) {
        *(code **)(DAT_0087b1c4 + 0x74) = FUN_004e55c0;
      }
      DAT_0087b1c8 = FUN_00578da0("deathstarbattle_a",0);
      DAT_0087b1cc = FUN_00578da0("deathstarbattle_b",0);
      DAT_0087b1d0 = FUN_00578da0("deathstarbattle_c",0);
      if (DAT_0087b1d0 != 0) {
        *(undefined1 **)(DAT_0087b1d0 + 0x78) = &LAB_004e5630;
      }
      DAT_0087b1d4 = FUN_00578da0("deathstarbattle_d",0);
      if (DAT_0087b1d4 != 0) {
        *(undefined **)(DAT_0087b1d4 + 0x6c) = &DAT_004e5b30;
        *(code **)(DAT_0087b1d4 + 0x74) = FUN_004e5ba0;
        *(undefined **)(DAT_0087b1d4 + 0x7c) = &DAT_004e5ea0;
        *(undefined1 **)(DAT_0087b1d4 + 0x70) = &LAB_004e5b40;
      }
      DAT_0087b1dc = FUN_00578da0("hothbattle_a",0);
      if (DAT_0087b1dc != 0) {
        *(undefined1 **)(DAT_0087b1dc + 0x6c) = &LAB_004e88c0;
        *(undefined1 **)(DAT_0087b1dc + 0x70) = &LAB_004e89f0;
        *(undefined1 **)(DAT_0087b1dc + 0x74) = &LAB_004e8a40;
        *(undefined1 **)(DAT_0087b1dc + 0x7c) = &LAB_004e8a50;
      }
      _DAT_0087b1e0 = FUN_00578da0("hothbattle_b",0);
      DAT_0087b1e4 = FUN_00578da0("hothbattle_c",0);
      if (DAT_0087b1e4 != 0) {
        *(undefined1 **)(DAT_0087b1e4 + 0x6c) = &LAB_004e8ad0;
        *(undefined1 **)(DAT_0087b1e4 + 0x70) = &LAB_004e8c50;
        *(undefined1 **)(DAT_0087b1e4 + 0x74) = &LAB_004e8cd0;
        *(undefined1 **)(DAT_0087b1e4 + 0x7c) = &LAB_004e8d10;
      }
      DAT_0087b1e8 = FUN_00578da0("hothbattle_d",0);
      DAT_0087b1ec = FUN_00578da0("hothbattle_e",0);
      if (DAT_0087b1ec != 0) {
        *(undefined1 **)(DAT_0087b1ec + 0x6c) = &LAB_004e9800;
        *(undefined1 **)(DAT_0087b1ec + 0x74) = &LAB_004e9ef0;
        *(undefined1 **)(DAT_0087b1ec + 0x7c) = &LAB_004e8d40;
        *(code **)(DAT_0087b1ec + 0x80) = FUN_004e8d50;
      }
      DAT_0087b1f0 = FUN_00578da0("HothBattle_Outro",0);
      DAT_0087b1f4 = FUN_00578da0("hothescape_a",0);
      if (DAT_0087b1f4 != 0) {
        *(undefined1 **)(DAT_0087b1f4 + 0x6c) = &LAB_004e6360;
        *(undefined1 **)(DAT_0087b1f4 + 0x74) = &LAB_004e6390;
        *(undefined **)(DAT_0087b1f4 + 0x70) = &DAT_004e6380;
      }
      DAT_0087b1f8 = FUN_00578da0("hothescape_b",0);
      if (DAT_0087b1f8 != 0) {
        *(undefined1 **)(DAT_0087b1f8 + 0x6c) = &LAB_004e63b0;
        *(undefined1 **)(DAT_0087b1f8 + 0x74) = &LAB_004e6470;
        *(code **)(DAT_0087b1f8 + 0x70) = FUN_004e6410;
      }
      DAT_0087b1fc = FUN_00578da0("hothescape_c",0);
      if (DAT_0087b1fc != 0) {
        *(undefined1 **)(DAT_0087b1fc + 0x6c) = &LAB_004e64d0;
        *(undefined1 **)(DAT_0087b1fc + 0x74) = &LAB_004e6500;
        *(undefined1 **)(DAT_0087b1fc + 0x78) = &LAB_004e6520;
        *(undefined **)(DAT_0087b1fc + 0x70) = &DAT_004e64f0;
      }
      DAT_0087b200 = FUN_00578da0("hothescape_d",0);
      if (DAT_0087b200 != 0) {
        *(undefined1 **)(DAT_0087b200 + 0x6c) = &LAB_004e6540;
        *(undefined1 **)(DAT_0087b200 + 0x74) = &LAB_004e6570;
        *(undefined **)(DAT_0087b200 + 0x70) = &DAT_004e6560;
      }
      DAT_0087b204 = FUN_00578da0("AsteroidChase_A",0);
      if (DAT_0087b204 != 0) {
        *(code **)(DAT_0087b204 + 0x6c) = FUN_004e6f40;
        *(undefined1 **)(DAT_0087b204 + 0x70) = &LAB_004e6f50;
        *(undefined1 **)(DAT_0087b204 + 0x74) = &LAB_004e6f60;
      }
      DAT_0087b208 = FUN_00578da0("AsteroidChase_B",0);
      if (DAT_0087b208 != 0) {
        *(undefined1 **)(DAT_0087b208 + 0x6c) = &LAB_004e6f70;
        *(undefined1 **)(DAT_0087b208 + 0x70) = &LAB_004e7080;
        *(code **)(DAT_0087b208 + 0x74) = FUN_004e7090;
      }
      DAT_0087b20c = FUN_00578da0("AsteroidChase_C",0);
      if (DAT_0087b20c != 0) {
        *(undefined1 **)(DAT_0087b20c + 0x6c) = &LAB_004e7260;
        *(undefined1 **)(DAT_0087b20c + 0x70) = &LAB_004e73c0;
        *(code **)(DAT_0087b20c + 0x74) = FUN_004e73d0;
      }
      DAT_0087b210 = FUN_00578da0("AsteroidChase_D",0);
      if (DAT_0087b210 != 0) {
        *(code **)(DAT_0087b210 + 0x6c) = FUN_004e7630;
        *(undefined1 **)(DAT_0087b210 + 0x74) = &LAB_004e77e0;
        *(undefined1 **)(DAT_0087b210 + 0x7c) = &LAB_004e7c60;
      }
      DAT_0087b214 = FUN_00578da0("AsteroidChase_Midtro",0);
      DAT_0087b238 = FUN_00578da0("dagobah_a",0);
      DAT_0087b244 = FUN_00578da0("dagobah_d",0);
      DAT_0087b248 = FUN_00578da0("dagobah_e",0);
      DAT_0087b248 = FUN_00578da0("dagobah_e",0);
      if (DAT_0087b248 != 0) {
        *(undefined1 **)(DAT_0087b248 + 0x6c) = &LAB_004e84c0;
      }
      DAT_0087b23c = FUN_00578da0("dagobah_b",0);
      if (DAT_0087b23c != 0) {
        *(undefined1 **)(DAT_0087b23c + 0x6c) = &LAB_004e8410;
        *(code **)(DAT_0087b23c + 0x70) = FUN_004e8420;
      }
      DAT_0087b240 = FUN_00578da0("dagobah_c",0);
      if (DAT_0087b240 != 0) {
        *(undefined1 **)(DAT_0087b240 + 0x6c) = &LAB_004e85b0;
        *(undefined1 **)(DAT_0087b240 + 0x80) = &LAB_004e85f0;
      }
      DAT_0087b224 = FUN_00578da0("CloudCityTrap_A",0);
      if (DAT_0087b224 != 0) {
        *(undefined1 **)(DAT_0087b224 + 0x6c) = &LAB_004e7c90;
        *(undefined1 **)(DAT_0087b224 + 0x74) = &LAB_004e7d10;
        *(undefined1 **)(DAT_0087b224 + 0x70) = &LAB_004e7cf0;
      }
      DAT_0087b228 = FUN_00578da0("CloudCityTrap_B",0);
      if (DAT_0087b228 != 0) {
        *(undefined1 **)(DAT_0087b228 + 0x6c) = &LAB_004e7dc0;
        *(undefined1 **)(DAT_0087b228 + 0x74) = &LAB_004e7e10;
      }
      DAT_0087b22c = FUN_00578da0("CloudCityTrap_C",0);
      if (DAT_0087b22c != 0) {
        *(undefined1 **)(DAT_0087b22c + 0x70) = &LAB_004e7ed0;
        *(undefined1 **)(DAT_0087b22c + 0x74) = &LAB_004e7f90;
        *(undefined1 **)(DAT_0087b22c + 0x80) = &LAB_004e8040;
      }
      DAT_0087b230 = FUN_00578da0("CloudCityTrap_Outro",0);
      DAT_0087b218 = FUN_00578da0("cloudcityescape_a",0);
      if (DAT_0087b218 != 0) {
        *(undefined1 **)(DAT_0087b218 + 0x6c) = &LAB_004e8080;
        *(undefined1 **)(DAT_0087b218 + 0x70) = &LAB_004e8100;
        *(undefined1 **)(DAT_0087b218 + 0x74) = &LAB_004e8160;
        *(undefined1 **)(DAT_0087b218 + 0x80) = &LAB_004e8240;
      }
      _DAT_0087b21c = FUN_00578da0("cloudcityescape_b",0);
      DAT_0087b220 = FUN_00578da0("cloudcityescape_c",0);
      if (DAT_0087b220 != 0) {
        *(code **)(DAT_0087b220 + 0x6c) = FUN_004e82b0;
        *(undefined1 **)(DAT_0087b220 + 0x74) = &LAB_004e8310;
      }
      DAT_0087b280 = FUN_00578da0("jabbaspalace_a",0);
      if (DAT_0087b280 != 0) {
        *(undefined1 **)(DAT_0087b280 + 0x6c) = &LAB_004ebba0;
        *(undefined1 **)(DAT_0087b280 + 0x70) = &LAB_004ebbc0;
        *(code **)(DAT_0087b280 + 0x74) = FUN_004ebbe0;
      }
      DAT_0087b284 = FUN_00578da0("jabbaspalace_b",0);
      if (DAT_0087b284 != 0) {
        *(code **)(DAT_0087b284 + 0x6c) = FUN_004ebc50;
        *(undefined1 **)(DAT_0087b284 + 0x70) = &LAB_004ebc80;
      }
      DAT_0087b288 = FUN_00578da0("jabbaspalace_d",0);
      if (DAT_0087b288 != 0) {
        *(undefined1 **)(DAT_0087b288 + 0x70) = &LAB_004ebca0;
      }
      DAT_0087b28c = FUN_00578da0("jabbaspalace_e",0);
      if (DAT_0087b28c != 0) {
        *(undefined1 **)(DAT_0087b28c + 0x6c) = &LAB_004ebcc0;
        *(code **)(DAT_0087b28c + 0x70) = FUN_004ebd10;
        *(undefined1 **)(DAT_0087b28c + 0x74) = &LAB_004ebda0;
        *(undefined1 **)(DAT_0087b28c + 0x80) = &LAB_004ec2f0;
      }
      DAT_0087b290 = FUN_00578da0("jabbaspalace_Outro",0);
      DAT_0087b294 = FUN_00578da0("endorbattle_a",0);
      if (DAT_0087b294 != 0) {
        *(undefined1 **)(DAT_0087b294 + 0x6c) = &LAB_004ee380;
        *(undefined1 **)(DAT_0087b294 + 0x74) = &LAB_004ee3a0;
      }
      DAT_0087b298 = FUN_00578da0("endorbattle_b",0);
      DAT_0087b29c = FUN_00578da0("endorbattle_c",0);
      DAT_0087b2a0 = FUN_00578da0("endorbattle_d",0);
      DAT_0087b24c = FUN_00578da0("DeathStar2Battle_A",0);
      if (DAT_0087b24c != 0) {
        *(undefined1 **)(DAT_0087b24c + 0x78) = &LAB_004e9f30;
      }
      DAT_0087b250 = FUN_00578da0("DeathStar2Battle_B",0);
      DAT_0087b254 = FUN_00578da0("DeathStar2Battle_D",0);
      if (DAT_0087b254 != 0) {
        *(undefined1 **)(DAT_0087b254 + 0x6c) = &LAB_004e9f50;
        *(undefined1 **)(DAT_0087b254 + 0x74) = &LAB_004ea110;
      }
      DAT_0087b258 = FUN_00578da0("DeathStar2Battle_E",0);
      if (DAT_0087b258 != 0) {
        *(undefined1 **)(DAT_0087b258 + 0x6c) = &LAB_004ee430;
        *(code **)(DAT_0087b258 + 0x74) = FUN_004ee4c0;
        *(undefined1 **)(DAT_0087b258 + 0x7c) = &LAB_004ea4a0;
      }
      DAT_0087b25c = FUN_00578da0("DeathStar2Battle_F",0);
      if (DAT_0087b25c != 0) {
        *(undefined1 **)(DAT_0087b25c + 0x6c) = &LAB_004ee430;
        *(code **)(DAT_0087b25c + 0x74) = FUN_004ee4c0;
        *(undefined1 **)(DAT_0087b25c + 0x7c) = &LAB_004ea4a0;
      }
      DAT_0087b260 = FUN_00578da0("DeathStar2Battle_G",0);
      if (DAT_0087b260 != 0) {
        *(undefined1 **)(DAT_0087b260 + 0x6c) = &LAB_004ee430;
        *(code **)(DAT_0087b260 + 0x74) = FUN_004ee4c0;
        *(undefined1 **)(DAT_0087b260 + 0x7c) = &LAB_004ea4a0;
      }
      DAT_0087b264 = FUN_00578da0("DeathStar2Battle_Midtro",0);
      DAT_0087b268 = FUN_00578da0("EmperorFight_A",0);
      if (DAT_0087b268 != 0) {
        *(undefined1 **)(DAT_0087b268 + 0x6c) = &LAB_004ea940;
        *(code **)(DAT_0087b268 + 0x70) = FUN_004eab80;
        *(undefined1 **)(DAT_0087b268 + 0x74) = &LAB_004eaf30;
        *(undefined1 **)(DAT_0087b268 + 0x80) = &LAB_004ebb60;
      }
      DAT_0087b26c = FUN_00578da0("SarlaccPit_A",0);
      if (DAT_0087b26c != 0) {
        *(code **)(DAT_0087b26c + 0x70) = FUN_004ec330;
        *(undefined1 **)(DAT_0087b26c + 0x7c) = &LAB_004ec390;
      }
      DAT_0087b270 = FUN_00578da0("SarlaccPit_B",0);
      if (DAT_0087b270 != 0) {
        *(code **)(DAT_0087b270 + 0x6c) = FUN_004ec7e0;
        *(code **)(DAT_0087b270 + 0x70) = FUN_004ecb50;
        *(code **)(DAT_0087b270 + 0x74) = FUN_004ece70;
      }
      DAT_0087b274 = FUN_00578da0("SarlaccPit_C",0);
      if (DAT_0087b274 != 0) {
        *(undefined1 **)(DAT_0087b274 + 0x6c) = &LAB_004ed6c0;
        *(code **)(DAT_0087b274 + 0x70) = FUN_004ed6e0;
        *(undefined1 **)(DAT_0087b274 + 0x74) = &LAB_004ed910;
      }
      DAT_0087b278 = FUN_00578da0("lego_city",0);
      if (DAT_0087b278 != 0) {
        *(undefined1 **)(DAT_0087b278 + 0x70) = &LAB_004edbb0;
        *(undefined1 **)(DAT_0087b278 + 0x74) = &LAB_004edc10;
      }
      DAT_0087b27c = FUN_00578da0("new_town",0);
      if (DAT_0087b27c != 0) {
        *(undefined1 **)(DAT_0087b27c + 0x6c) = &LAB_004edfb0;
        *(code **)(DAT_0087b27c + 0x70) = FUN_004edfe0;
        *(undefined1 **)(DAT_0087b27c + 0x74) = &LAB_004ee0a0;
      }
    }
  }
  iVar4 = 0;
  iVar3 = DAT_00951b78;
  if (0 < DAT_00951b84) {
    do {
      if (((*(uint *)(iVar3 + 100) & 0x400) != 0) || (iVar3 == DAT_00951b98)) {
        *(code **)(iVar3 + 0x74) = FUN_00486c60;
        *(undefined1 **)(iVar3 + 0x80) = &LAB_00486200;
      }
      iVar4 = iVar4 + 1;
      iVar3 = iVar3 + 0x130;
    } while (iVar4 < DAT_00951b84);
  }
  return;
}

