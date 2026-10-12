/* Ghidra pseudocode, not original source.
 * ev_4e08cb6b9a05324ae7a2b7ff12e5cd4300e2bf96324e358c1c445da0c9e3f38b
 * Entry: 0x630e00; label: FUN_00630e00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00630e00(int param_1)

{
  int *piVar1;
  undefined1 *puVar2;
  int *extraout_ECX;
  int *piVar3;
  int iVar4;
  int iVar5;
  code *local_140;
  undefined4 local_13c;
  undefined4 local_138;
  undefined4 local_134;
  uint local_130;
  undefined *local_12c [4];
  undefined *local_11c;
  undefined *local_118;
  undefined *local_114;
  undefined *local_110;
  undefined *local_10c;
  undefined *local_108;
  undefined1 local_104;
  undefined1 local_103 [255];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_140;
  local_134 = 0x3f800000;
  iVar4 = 0;
  iVar5 = 0;
  local_140 = (code *)0x0;
  local_13c = 1;
  local_130 = 0;
  local_138 = 0;
  piVar1 = (int *)register0x00000010;
  if (param_1 != 1) {
    do {
      piVar3 = piVar1 + 1;
      iVar5 = iVar5 + 1;
      switch(param_1) {
      case 0:
      case 3:
      case 9:
        break;
      default:
        local_12c[0] = &DAT_0076b1e8;
        local_12c[1] = &DAT_0076b1e4;
        local_12c[2] = &DAT_0076b1e0;
        local_12c[3] = &DAT_0076b1dc;
        local_11c = &DAT_0076b1e8;
        local_118 = &DAT_0076b1e8;
        local_114 = &DAT_0076b1e8;
        local_110 = &DAT_0076b1e8;
        local_10c = &DAT_0076b1e8;
        local_108 = &DAT_0076b1e8;
        FUN_00630d60(iVar5,local_12c[iVar5 % 10],param_1);
        piVar3 = extraout_ECX;
        break;
      case 2:
        iVar4 = piVar1[2];
        piVar3 = piVar1 + 2;
        break;
      case 4:
        piVar3 = piVar1 + 2;
        local_130 = (uint)(*piVar3 == 3);
        break;
      case 5:
      case 6:
      case 10:
      case 0xb:
      case 0xc:
        piVar3 = piVar1 + 2;
        break;
      case 7:
        local_140 = (code *)piVar1[2];
        piVar3 = piVar1 + 2;
        break;
      case 8:
        piVar3 = piVar1 + 3;
        break;
      case 0xd:
        local_13c = 0;
        break;
      case 0xe:
        local_134 = *(undefined4 *)piVar1[2];
        piVar3 = piVar1 + 2;
        break;
      case 0xf:
        DAT_02913150 = piVar1[2];
        piVar3 = piVar1 + 2;
      }
      param_1 = piVar3[1];
      piVar1 = piVar3;
    } while (param_1 != 1);
    if (iVar4 != 0) {
      FUN_00698f20(local_13c);
      FUN_004f6900(&local_104);
      FUN_004f1e80(&local_104,iVar4);
      puVar2 = (undefined1 *)FUN_004f8a70(local_103,&DAT_0075ebb0);
      if (puVar2 != (undefined1 *)0x0) {
        *puVar2 = 0;
      }
      FUN_004f1e80(&local_104,&DAT_0075eaf0);
      iVar4 = FUN_00631170(&local_104,local_134,local_130);
      if (iVar4 != 0) {
        local_138 = 1;
        FUN_004fb130();
        FUN_006dd390();
        FUN_006d3420();
        iVar4 = FUN_00631210();
        while (iVar4 != 0) {
          if (local_140 != (code *)0x0) {
            iVar4 = (*local_140)();
            if (iVar4 == 1) break;
            if (iVar4 == 2) {
              FUN_00631270();
            }
          }
          FUN_006d9610();
          FUN_004fb130();
          FUN_006dd390();
          FUN_006d3420();
          iVar4 = FUN_00631210();
        }
      }
      FUN_00631160();
    }
  }
  FUN_006d6b50();
  FUN_004fb130();
  __security_check_cookie(local_4 ^ (uint)&local_140);
  return;
}

