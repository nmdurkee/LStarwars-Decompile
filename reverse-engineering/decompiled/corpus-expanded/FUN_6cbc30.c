/* Ghidra pseudocode, not original source.
 * ev_78df0822e84eed863df7f286a1c553c9b84caeaa7e7dd857dd35c61ca827b7f8
 * Entry: 0x6cbc30; label: FUN_006cbc30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_006cbc30(int param_1,undefined4 *param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int in_ECX;
  float10 fVar4;
  float local_80;
  float local_7c;
  float local_78;
  undefined4 local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_60;
  float local_5c;
  float local_58;
  float local_50;
  float local_4c;
  float local_48;
  float local_40;
  float local_3c;
  float local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  float local_20;
  float local_1c;
  float local_18;
  
  FUN_006cb940(param_1,param_2);
  iVar3 = FUN_006ca2f0(&local_80);
  if (iVar3 == 0) {
    return false;
  }
  iVar3 = FUN_006c4600(param_1,&local_80,&local_70,&local_20,0);
  _DAT_02973c1c = *(undefined4 *)(&DAT_0081f9b8 + iVar3 * 4);
  if (((*(char *)(param_1 + 0x53) != '\0') && (*(float *)(param_1 + 0x124) != 0.0)) ||
     ((*(char *)(param_1 + 0x76) != '\0' && (*(float *)(param_1 + 0x1b0) != 0.0)))) {
    for (param_2 = (undefined4 *)*param_2; param_2 != (undefined4 *)0x0;
        param_2 = (undefined4 *)*param_2) {
      local_80 = 0.0;
      local_7c = 0.0;
      local_78 = 0.0;
      local_74 = 0x3f800000;
      FUN_006c8760(8,DAT_02973ab8,&local_80,0);
      switch(iVar3) {
      case 1:
      case 2:
      case 3:
        fVar1 = local_6c * *(float *)(in_ECX + 0x54) + local_70 * *(float *)(in_ECX + 0x50) +
                local_68 * *(float *)(in_ECX + 0x58);
        if (fVar1 != 0.0) {
          local_60 = fVar1 * local_70;
          local_5c = fVar1 * local_6c;
          local_58 = local_68 * fVar1;
          local_80 = local_60 + local_80;
          local_7c = local_5c + local_7c;
          local_78 = local_58 + local_78;
          goto LAB_006cbf0e;
        }
        break;
      case 4:
      case 5:
      case 6:
        fVar1 = local_6c * *(float *)(in_ECX + 0x54) + local_70 * *(float *)(in_ECX + 0x50) +
                local_68 * *(float *)(in_ECX + 0x58);
        if (fVar1 != 0.0) {
          local_50 = fVar1 * local_70;
          local_4c = fVar1 * local_6c;
          local_48 = local_68 * fVar1;
          local_80 = local_50 + local_80;
          local_7c = local_4c + local_7c;
          local_78 = local_48 + local_78;
        }
        fVar2 = local_20 * *(float *)(in_ECX + 0x50) + local_1c * *(float *)(in_ECX + 0x54) +
                local_18 * *(float *)(in_ECX + 0x58);
        if (fVar2 == 0.0) {
          if (fVar1 == 0.0) break;
        }
        else {
          local_40 = local_20 * fVar2;
          local_3c = local_1c * fVar2;
          local_38 = local_18 * fVar2;
          local_80 = local_40 + local_80;
          local_7c = local_3c + local_7c;
          local_78 = local_38 + local_78;
        }
LAB_006cbf0e:
        if ((DAT_0081fad4 == 1) || (DAT_0081fad4 == 2)) {
          local_2c = DAT_0081fac4;
          local_28 = DAT_0081fac8;
          local_30 = DAT_0081fac0;
          local_24 = DAT_0081facc;
          FUN_005b3b30(&local_30,&local_30);
        }
        FUN_006c87f0(8,DAT_02973ab8,&local_80,0);
        break;
      case 7:
        fVar4 = (float10)FUN_006b97c0(0x26);
        if ((float10)0 != fVar4) {
          local_80 = _DAT_02973c00;
          local_7c = _DAT_02973c04;
          local_78 = _DAT_02973c08;
          local_74 = _DAT_02973c0c;
          goto LAB_006cbf0e;
        }
      }
    }
  }
  return iVar3 != 0;
}

