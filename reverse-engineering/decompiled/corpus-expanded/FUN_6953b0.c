/* Ghidra pseudocode, not original source.
 * ev_5f11e12836052333f8ad93b61631d5915def4fdf8e192d080659a6ddfc49976b
 * Entry: 0x6953b0; label: FUN_006953b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006953b0(int param_1)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *extraout_ECX;
  int iVar4;
  int iVar5;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  int local_18;
  int local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  float local_4;
  
  if (DAT_02962bac == 0) {
    return 0;
  }
  local_4 = 0.0;
  iVar5 = -1;
  iVar4 = -1;
  local_1c = 0;
  local_20 = 0xffffffff;
  local_14 = 0xffffffff;
  local_18 = -1;
  local_c = 0x3fff;
  local_10 = 0x3fff;
  local_8 = 0xffffffff;
  puVar3 = (undefined1 *)register0x00000010;
  puVar1 = (undefined1 *)register0x00000010;
  if (param_1 != 1) {
    do {
      puVar2 = puVar1 + 4;
      switch(param_1) {
      case 0:
        break;
      default:
        puVar2 = (undefined1 *)FUN_00693b60();
        puVar3 = extraout_ECX;
        break;
      case 2:
        local_1c = *(undefined4 *)(puVar1 + 8);
        puVar3 = puVar3 + 4;
        puVar2 = puVar1 + 8;
        break;
      case 3:
        iVar4 = *(int *)(puVar1 + 8);
        puVar3 = puVar3 + 4;
        puVar2 = puVar1 + 8;
        iVar5 = iVar4 + 1;
        break;
      case 4:
        iVar4 = *(int *)(puVar1 + 8);
        puVar3 = puVar3 + 4;
        puVar2 = puVar1 + 8;
        break;
      case 5:
        iVar5 = *(int *)(puVar1 + 8);
        puVar3 = puVar3 + 4;
        puVar2 = puVar1 + 8;
        break;
      case 6:
        local_10 = *(undefined4 *)(puVar1 + 8);
        puVar3 = puVar3 + 4;
        puVar2 = puVar1 + 8;
        local_c = local_10;
        break;
      case 7:
        local_10 = *(undefined4 *)(puVar1 + 8);
        puVar3 = puVar3 + 4;
        puVar2 = puVar1 + 8;
        break;
      case 8:
        local_c = *(undefined4 *)(puVar1 + 8);
        puVar3 = puVar3 + 4;
        puVar2 = puVar1 + 8;
        break;
      case 9:
        local_8 = *(undefined4 *)(puVar1 + 8);
        puVar3 = puVar3 + 4;
        puVar2 = puVar1 + 8;
        break;
      case 10:
        local_4 = (float)*(double *)(puVar3 + 8);
        puVar3 = puVar3 + 8;
        puVar2 = puVar1 + 0xc;
        break;
      case 0xb:
        local_24 = *(undefined4 *)(puVar1 + 8);
        puVar3 = puVar3 + 4;
        puVar2 = puVar1 + 8;
        break;
      case 0xc:
        local_8 = 0;
      }
      param_1 = *(int *)(puVar2 + 4);
      puVar3 = puVar3 + 4;
      puVar1 = puVar2;
    } while (param_1 != 1);
    local_18 = iVar4;
    local_14 = iVar5;
    if (iVar5 != -1) goto LAB_006954f0;
  }
  local_14 = local_18 + 1;
LAB_006954f0:
  FUN_00698520(&local_24);
  return 1;
}

