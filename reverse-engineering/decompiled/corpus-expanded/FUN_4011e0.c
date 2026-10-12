/* Ghidra pseudocode, not original source.
 * ev_48d4eb782bac12eedeead3c338e4f978b0df7732be8621fd20cf56d53bd7b1ed
 * Entry: 0x4011e0; label: FUN_004011e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004011e0(void)

{
  undefined1 local_80;
  undefined1 local_7f;
  undefined1 local_7e;
  undefined1 local_7d;
  undefined1 local_7c;
  undefined1 local_7b;
  undefined1 local_7a;
  undefined1 local_79;
  undefined1 local_78;
  undefined1 local_77;
  undefined1 local_76;
  undefined1 local_75;
  undefined1 local_74;
  undefined1 local_73;
  undefined1 local_72;
  undefined1 local_71;
  undefined1 local_70;
  undefined1 local_6f;
  undefined1 local_6e;
  undefined1 local_6d;
  undefined2 local_6c;
  undefined2 local_6a;
  undefined2 local_68;
  undefined2 local_66;
  undefined2 local_64;
  undefined2 local_62;
  undefined2 local_60;
  undefined2 local_5e;
  undefined2 local_5c;
  undefined2 local_5a;
  undefined2 local_58;
  undefined2 local_56;
  undefined2 local_54;
  undefined2 local_52;
  undefined2 local_50;
  undefined2 local_4e;
  undefined2 local_4c;
  undefined2 local_4a;
  undefined2 local_48;
  undefined2 local_46;
  undefined2 local_44;
  undefined2 local_42;
  undefined2 local_40;
  undefined2 local_3e;
  undefined2 local_3c;
  undefined2 local_38;
  undefined2 local_36;
  undefined2 local_34;
  undefined2 local_32;
  undefined2 local_30;
  undefined2 local_2e;
  undefined2 local_2c;
  undefined2 local_2a;
  undefined2 local_28;
  undefined2 local_26;
  undefined2 local_24;
  undefined2 local_22;
  undefined2 local_20;
  undefined2 local_1e;
  undefined2 local_1c;
  undefined2 local_1a;
  undefined2 local_18;
  undefined2 local_16;
  undefined2 local_14;
  undefined2 local_12;
  undefined2 local_10;
  undefined2 local_e;
  undefined2 local_c;
  undefined2 local_a;
  undefined2 local_8;
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_80;
  FUN_006dc890("LUCASARTS\\LEGOSTARWARSSAGA");
  _DAT_00924870 = FUN_004eef40(DAT_007ef01c,".\\pcbatman.cpp",0x112);
  DAT_009248ac = DAT_007ef01c + _DAT_00924870;
  DAT_00924874 = _DAT_00924870;
  FUN_00428b90();
  FUN_00401100();
  FUN_004f6930(&DAT_00854708);
  FUN_00602930(0x3f800000,0x3f000000,0);
  DAT_009253ac = &DAT_00926bb0;
  local_38 = 0x1e;
  local_36 = 0x20;
  local_34 = 0x11;
  local_32 = 0x1f;
  local_30 = 0xffff;
  local_2e = 0xffff;
  local_2c = 0xffff;
  local_2a = 0xffff;
  local_28 = 0xffff;
  local_26 = 0xffff;
  local_24 = 0x1d;
  local_22 = 0x39;
  local_20 = 0x25;
  local_1e = 0x24;
  local_1c = 0x16;
  local_1a = 0x23;
  local_18 = 0xffff;
  local_16 = 0xffff;
  local_14 = 0xffff;
  local_12 = 0x1c;
  local_10 = 0xffff;
  local_e = 0xffff;
  local_c = 0xffff;
  local_a = 0xffff;
  local_8 = 0xffff;
  local_6c = 0xcb;
  local_6a = 0xcd;
  local_68 = 200;
  local_66 = 0xd0;
  local_64 = 0xffff;
  local_62 = 0xffff;
  local_60 = 0xffff;
  local_5e = 0xffff;
  local_5c = 0xffff;
  local_5a = 0xffff;
  local_58 = 0x9d;
  local_56 = 0x52;
  local_54 = 0x51;
  local_52 = 0x50;
  local_50 = 0x4c;
  local_4e = 0x4f;
  local_4c = 0xffff;
  local_4a = 0xffff;
  local_48 = 0xffff;
  local_46 = 0x9c;
  local_44 = 0xffff;
  local_42 = 0xffff;
  local_40 = 0xffff;
  local_3e = 0xffff;
  local_3c = 0xffff;
  local_6d = 0xff;
  local_80 = 0;
  local_7f = 1;
  local_7e = 2;
  local_7d = 3;
  local_7c = 0xc;
  local_7b = 0xd;
  local_7a = 0xe;
  local_79 = 0xf;
  local_78 = 0x10;
  local_77 = 0x12;
  local_76 = 0x17;
  local_75 = 4;
  local_74 = 5;
  local_73 = 6;
  local_72 = 7;
  local_71 = 8;
  local_70 = 10;
  local_6f = 0xb;
  local_6e = 9;
  FUN_006d62a0(&local_38,0,&local_6c,0,&local_80);
  FUN_006dbb30(&DAT_00924874,&DAT_009248ac,0,4,DAT_00854814,0x18,&PTR_s_GAME_DAT_007ef090,7,6,
               DAT_007ef00c,7,DAT_00854818,8,0x500000,0x12,-(DAT_009250b0 != 0) & 8,0x21,0x200,
               (-(uint)(DAT_009250b0 != 0) & 0x20) + 0xe0,0x1a,0x1000,0x15,1,5,&DAT_0085480c,
               (-(DAT_02962034 != 0) & 0x12U) + 10,0,0x640,0,0,0xb,5,0x1fff,0xe,DAT_009253ac,0xf,
               DAT_009253ac + 4,0x2e,&DAT_007514d0,0x2d,&DAT_007514d0,0x2f,
               "LUCASARTS\\LEGOSTARWARSSAGA",0x30,"LucasArts",0x31,
               "LEGO Star Wars - The Complete Saga",0x34,DAT_00854704,0x46,1,0x47,1,0x49,1,0x4b,1,0)
  ;
  FUN_005ede60();
  DAT_00925164 = FUN_005d5330();
  FUN_004badd0(DAT_008668d7);
  _DAT_00925020 = FUN_005d8270(0);
  _DAT_00924fec = FUN_005d8270(0);
  _DAT_00924ff0 = FUN_005d8270(0);
  _DAT_00924ff4 = FUN_005d8270(0);
  DAT_008668cf = DAT_00826498;
  DAT_008668d0 = DAT_0082649c;
  DAT_008668d1 = DAT_008264a0;
  FUN_00547b20(&DAT_008668cc);
  FUN_00547ab0(&DAT_008668cc);
  FUN_00543e80(&DAT_00924874,DAT_0092487c,0x7e4c,&DAT_0087b4c0,PTR_s_lego_ico_007fabb4,
               s_LEGO_Star_Wars_Saga_007fabb8,4);
  __security_check_cookie(local_4 ^ (uint)&local_80);
  return;
}

