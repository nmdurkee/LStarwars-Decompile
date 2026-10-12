/* Ghidra pseudocode, not original source.
 * ev_d9eb3013c9fda622502628697ce0d7be845892a91a12bfef10a3ae0a3a8d7789
 * Entry: 0x6dbb30; label: FUN_006dbb30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_006dbb30(int *param_1,int *param_2,int param_3)

{
  int *piVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  undefined4 uVar7;
  int local_c4;
  int local_c0;
  int local_bc;
  int local_b8;
  int local_ac;
  int local_a8;
  int local_a4;
  int local_a0;
  int local_9c;
  int local_98;
  int local_94;
  int local_90;
  int local_8c;
  int local_88;
  int local_84;
  int local_80;
  int local_7c;
  int local_78;
  int local_74;
  int local_70;
  undefined4 *local_6c;
  int local_68;
  undefined4 *local_64;
  int local_60;
  undefined4 *local_5c;
  int local_58;
  undefined4 *local_54;
  int local_50;
  int local_4c;
  char *local_48;
  undefined *local_44;
  
  local_a0 = 0xa0;
  local_a4 = 0;
  local_c4 = 0;
  local_88 = 0;
  local_bc = 1;
  local_70 = 0x200000;
  local_a8 = 0;
  local_8c = 0;
  local_7c = 0;
  local_74 = 0;
  bVar2 = false;
  local_94 = 0;
  local_9c = 0;
  local_6c = (undefined4 *)0x0;
  local_64 = (undefined4 *)0x0;
  local_5c = (undefined4 *)0x0;
  local_54 = (undefined4 *)0x0;
  local_78 = 0x800;
  local_50 = 0;
  iVar4 = 0xe0;
  local_58 = 0x400;
  local_84 = 3;
  local_44 = PTR_s_TitleNotSet_00827614;
  local_48 = "TTalesKey";
  local_68 = 0;
  local_c0 = 0;
  local_ac = 0;
  local_98 = 0;
  local_90 = 0;
  local_b8 = 1;
  local_60 = 0;
  local_4c = 0;
  local_80 = 0;
  FUN_004f3db0();
  if (param_3 != 0) {
    iVar3 = FUN_004eef40(0x4000000,".\\pcapi.cpp",0xb2);
    *param_1 = iVar3;
    *param_2 = iVar3 + 0x4000000;
  }
  FUN_004ff100();
  FUN_00602930(0x3f800000,0x3f000000,0);
  piVar5 = &param_3;
LAB_006dbc64:
  do {
    piVar1 = piVar5 + 1;
    piVar6 = piVar5 + 1;
    switch(*piVar1) {
    case 4:
      local_88 = piVar5[2];
      piVar5 = piVar5 + 2;
      goto LAB_006dbc64;
    case 5:
    case 0x15:
    case 0x1b:
    case 0x1f:
    case 0x20:
    case 0x22:
    case 0x26:
    case 0x27:
    case 0x28:
    case 0x29:
    case 0x2a:
    case 0x36:
    case 0x37:
    case 0x3b:
    case 0x45:
    case 0x46:
    case 0x47:
    case 0x48:
    case 0x49:
    case 0x4b:
    case 0x4e:
      piVar5 = piVar5 + 2;
      goto LAB_006dbc64;
    case 6:
      local_bc = piVar5[2];
      piVar5 = piVar5 + 2;
      goto LAB_006dbc64;
    case 7:
      local_50 = piVar5[2];
      piVar5 = piVar5 + 2;
      goto LAB_006dbc64;
    case 8:
      local_70 = piVar5[2];
      piVar5 = piVar5 + 2;
      goto LAB_006dbc64;
    case 9:
    case 0x14:
    case 0x1e:
    case 0x35:
      piVar5 = piVar5 + 3;
      goto LAB_006dbc64;
    case 10:
      local_a8 = piVar5[2];
      local_8c = piVar5[3];
      local_7c = piVar5[4];
      piVar5 = piVar5 + 5;
      local_74 = *piVar5;
      bVar2 = true;
      goto LAB_006dbc64;
    case 0xb:
      local_94 = piVar5[2];
      local_9c = piVar5[3];
      piVar5 = piVar5 + 3;
      goto LAB_006dbc64;
    case 0xe:
      local_6c = (undefined4 *)piVar5[2];
      piVar5 = piVar5 + 2;
      goto LAB_006dbc64;
    case 0xf:
      local_64 = (undefined4 *)piVar5[2];
      piVar5 = piVar5 + 2;
      goto LAB_006dbc64;
    case 0x10:
      local_5c = (undefined4 *)piVar5[2];
      piVar5 = piVar5 + 2;
      goto LAB_006dbc64;
    case 0x11:
      local_54 = (undefined4 *)piVar5[2];
      piVar5 = piVar5 + 2;
      goto LAB_006dbc64;
    case 0x12:
      piVar5 = piVar5 + 2;
      if ((iVar4 == 0xe0) && ((*piVar5 == 2 || (*piVar5 == 8)))) {
        iVar4 = 0x100;
      }
      goto LAB_006dbc64;
    case 0x13:
      piVar5 = piVar5 + 4;
      goto LAB_006dbc64;
    case 0x16:
      PTR_DAT_00826584 = (undefined *)piVar5[2];
      piVar5 = piVar5 + 2;
      goto LAB_006dbc64;
    case 0x17:
      PTR_DAT_00826580 = (undefined *)piVar5[2];
      piVar5 = piVar5 + 2;
      goto LAB_006dbc64;
    case 0x18:
      local_a4 = piVar5[2];
      local_c4 = piVar5[3];
      piVar5 = piVar5 + 3;
      goto LAB_006dbc64;
    case 0x19:
      _DAT_029759d0 = piVar5[2];
      piVar5 = piVar5 + 2;
      goto LAB_006dbc64;
    case 0x1a:
      local_78 = piVar5[2];
      piVar5 = piVar5 + 2;
      goto LAB_006dbc64;
    case 0x1c:
      bVar2 = false;
      piVar5 = piVar5 + 5;
      goto LAB_006dbc64;
    case 0x21:
      iVar4 = piVar5[3];
      piVar5 = piVar5 + 3;
      goto LAB_006dbc64;
    case 0x23:
      piVar5 = piVar5 + 3;
      goto LAB_006dbc64;
    case 0x24:
      local_84 = piVar5[2];
      piVar5 = piVar5 + 2;
      goto LAB_006dbc64;
    case 0x25:
      local_58 = piVar5[2];
      piVar5 = piVar5 + 2;
      goto LAB_006dbc64;
    case 0x2d:
      local_68 = piVar5[2];
      piVar5 = piVar5 + 2;
      goto LAB_006dbc64;
    case 0x2e:
      local_44 = (undefined *)piVar5[2];
      piVar5 = piVar5 + 2;
      goto LAB_006dbc64;
    case 0x2f:
      local_48 = (char *)piVar5[2];
      piVar5 = piVar5 + 2;
      goto LAB_006dbc64;
    case 0x30:
      local_c0 = piVar5[2];
      piVar5 = piVar5 + 2;
      goto LAB_006dbc64;
    case 0x31:
      local_ac = piVar5[2];
      piVar5 = piVar5 + 2;
      goto LAB_006dbc64;
    case 0x32:
      local_98 = piVar5[2];
      piVar5 = piVar5 + 2;
      goto LAB_006dbc64;
    case 0x33:
      local_90 = piVar5[2];
      piVar5 = piVar5 + 2;
      goto LAB_006dbc64;
    case 0x34:
      local_b8 = piVar5[2];
      piVar5 = piVar5 + 2;
      goto LAB_006dbc64;
    case 0x38:
    case 0x39:
    case 0x3a:
      piVar6 = piVar5 + 2;
      break;
    case 0x3c:
      local_60 = piVar5[2];
      piVar5 = piVar5 + 2;
      goto LAB_006dbc64;
    case 0x44:
      local_a0 = piVar5[2];
      piVar5 = piVar5 + 2;
      goto LAB_006dbc64;
    case 0x4c:
      local_4c = piVar5[2];
      piVar5 = piVar5 + 2;
      goto LAB_006dbc64;
    case 0x4f:
      DAT_02975c54 = piVar5[2];
      piVar6 = piVar5 + 2;
    case 0x53:
      local_80 = piVar6[1];
      piVar6 = piVar6 + 1;
      break;
    case 0x52:
      piVar1 = piVar5 + 2;
      piVar5 = piVar5 + 2;
      FUN_004f4790(*piVar1);
      goto LAB_006dbc64;
    }
    piVar5 = piVar6;
  } while (*piVar1 != 0);
  if ((local_c0 != 0) && (local_ac != 0)) {
    FUN_006ddd50(local_c0,local_ac,local_44,0);
  }
  FUN_006e2ba0();
  FUN_006db940();
  FUN_006db990();
  FUN_006dc890(local_48);
  FUN_006d3150();
  if (local_98 != 0) {
    FUN_006ddd90(local_98);
  }
  if (local_68 != 0) {
    FUN_006ddd40(local_68);
  }
  if (local_90 != 0) {
    FUN_006dddb0(local_90);
  }
  DAT_02976c24 = local_b8 == 1;
  FUN_004f9940(local_88,local_bc,local_50);
  iVar4 = FUN_006db910();
  FUN_004f78b0(iVar4 == 0);
  FUN_006daff0(2);
  if (DAT_02974d1c < 4) {
    FUN_006db070(0);
    FUN_006db0a0(0);
    FUN_006db1c0();
  }
  if (DAT_02976b94 == 0x10de) {
    if (DAT_02976b98 < 0x1e0) {
      if (DAT_02976b98 != 0x1df) {
        switch(DAT_02976b98) {
        case 0xf3:
        case 0x14f:
        case 0x161:
        case 0x162:
        case 0x163:
          break;
        default:
          goto switchD_006dc020_caseD_f4;
        }
      }
    }
    else if ((DAT_02976b98 != 0x221) && (DAT_02976b98 != 0x7e1)) goto switchD_006dc020_caseD_f4;
switchD_006dc020_caseD_f3:
    FUN_006db070(0);
    FUN_006db0a0(0);
    FUN_006db1c0();
  }
  else if (DAT_02976b94 == 0x1002) {
    switch(DAT_02976b98) {
    case 0x7142:
    case 0x7146:
    case 0x714d:
    case 0x714e:
    case 0x715e:
    case 0x7162:
    case 0x7166:
    case 0x716d:
    case 0x716e:
    case 0x717e:
    case 0x7180:
    case 0x7183:
    case 0x7187:
    case 0x718f:
    case 0x71a0:
    case 0x71a3:
    case 0x71a7:
    case 0x71af:
    case 0x71c3:
    case 0x71e3:
      goto switchD_006dc020_caseD_f3;
    default:
      break;
    }
  }
switchD_006dc020_caseD_f4:
  if (DAT_008264c7 == '\0') {
    FUN_006db020(1);
    uVar7 = 1;
  }
  else {
    DAT_02976c30 = 0;
    FUN_006db020(2);
    uVar7 = 2;
  }
  FUN_006db000(uVar7);
  FUN_006db060(1);
  FUN_004f9940(local_88,local_bc,local_50);
  if (local_60 == 0) {
    if (local_b8 == 0) {
      DAT_00924868 = local_60;
    }
    iVar4 = FUN_006de4b0(DAT_00924860,DAT_00924868,local_80);
    if (iVar4 == 0) {
                    /* WARNING: Subroutine does not return */
      _exit(1);
    }
  }
  else {
    iVar4 = FUN_006dd2b0(local_60,DAT_00924868);
    if (iVar4 == 0) {
                    /* WARNING: Subroutine does not return */
      _exit(1);
    }
  }
  FUN_00600b10(param_1,*param_2);
  FUN_00605660(param_1,*param_2);
  FUN_006d33d0();
  DAT_0297dbd0 = DAT_00826494;
  if (DAT_00826494 == 3) {
    DAT_0297dbd0 = DAT_02976bf4;
  }
  SetCursor((HCURSOR)0x0);
  iVar4 = FUN_006e45a0();
  if (iVar4 == 0) {
    FUN_006e57d0(0);
  }
  FUN_005fe3f0();
  FUN_00609060();
  FUN_005bdd50();
  FUN_00607bc0();
  FUN_00603350(param_1,*param_2);
  FUN_00741230(param_1,*param_2);
  if (((PTR_DAT_00826584 != (undefined *)0x0) && (*PTR_DAT_00826584 != '\0')) ||
     ((PTR_DAT_00826580 != (undefined *)0x0 && (*PTR_DAT_00826580 != '\0')))) {
    if ((PTR_DAT_00826584 != (undefined *)0x0) && (*PTR_DAT_00826584 != '\0')) {
      local_c4 = local_c4 + 1;
    }
    if ((PTR_DAT_00826580 != (undefined *)0x0) && (*PTR_DAT_00826580 != '\0')) {
      local_c4 = local_c4 + 1;
    }
    local_a4 = FUN_004eef40(local_c4 * 4,".\\pcapi.cpp",0x2a0);
    if ((PTR_DAT_00826584 != (undefined *)0x0) && (*PTR_DAT_00826584 != '\0')) {
      FUN_004ef660(local_a4,&PTR_DAT_00826584,4);
    }
    if ((PTR_DAT_00826580 != (undefined *)0x0) && (*PTR_DAT_00826580 != '\0')) {
      FUN_004ef660(local_a4 + 4,&PTR_DAT_00826580,4);
    }
  }
  FUN_006d3440(local_a4,local_c4,param_1);
  FUN_005e51a0(param_1,local_78);
  FUN_005f1dd0(param_1,local_58);
  FUN_00607ba0(local_70,param_1,*param_2);
  FUN_00601a30();
  FUN_0060cb00();
  FUN_005d16a0(param_1,*param_2);
  FUN_00607c60(param_1,*param_2);
  FUN_0060a5f0(DAT_02976c20,0,param_1,*param_2);
  FUN_005f22a0(DAT_02976c1c,param_1,*param_2);
  FUN_00605e60(param_1,*param_2);
  FUN_005fa240();
  FUN_005eaa80(param_1,*param_2);
  FUN_004ffbb0();
  FUN_005ede60();
  FUN_005e9020(local_a0,param_1,*param_2);
  FUN_005d3370();
  if (bVar2) {
    FUN_006951f0(param_1,*param_2,local_84,1,local_a8,2,local_8c,3,local_94,4,local_9c,0);
  }
  if (((local_a8 != 0) && (local_7c != 0)) && (local_74 != 0)) {
    FUN_00698710(local_7c,local_74);
  }
  FUN_00698e70();
  FUN_00600b20(0);
  FUN_005d0940(1);
  FUN_004f4920();
  if (local_6c != (undefined4 *)0x0) {
    uVar7 = FUN_004f41f0(0,0);
    *local_6c = uVar7;
  }
  if (local_64 != (undefined4 *)0x0) {
    uVar7 = FUN_004f41f0(1,0);
    *local_64 = uVar7;
  }
  if (local_5c != (undefined4 *)0x0) {
    uVar7 = FUN_004f41f0(2,0);
    *local_5c = uVar7;
  }
  if (local_54 != (undefined4 *)0x0) {
    uVar7 = FUN_004f41f0(3,0);
    *local_54 = uVar7;
  }
  FUN_005e4eb0(0x200,param_1,param_2);
  FUN_006daea0(1);
  FUN_005f2800(local_4c,param_1,*param_2);
  FUN_006ddec0();
  FUN_005d4290(1);
  FUN_005ebd80(0xb00,0,0x3f800000);
  FUN_005f3950();
  FUN_0060aff0(0);
  FUN_004feef0();
  return 1;
}

