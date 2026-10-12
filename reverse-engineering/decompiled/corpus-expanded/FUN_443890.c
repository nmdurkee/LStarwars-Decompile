/* Ghidra pseudocode, not original source.
 * ev_49c5de326560f696c25fe7c48a171edc0aeca1661cc4385396c06e099fff9572
 * Entry: 0x443890; label: FUN_00443890
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00443890(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  float10 fVar3;
  float local_10;
  undefined1 local_c [12];
  
  local_10 = 1e+09;
  if (((param_3 != 0) && (*(int *)(param_3 + 0xd0) != 0)) && (param_1 != 0)) {
    piVar2 = &DAT_0093d7f0;
    do {
      iVar1 = *piVar2;
      if (((iVar1 != 0) && ((*(uint *)(iVar1 + 0x1fc) & 1) != 0)) &&
         ((*(uint *)(iVar1 + 0x1fc) & 0x1000) != 0)) {
        fVar3 = (float10)FUN_005b3cf0(iVar1 + 0x5c,*(int *)(param_3 + 0xd0) + 0x5c,local_c);
        if ((float)fVar3 < local_10) {
          local_10 = (float)fVar3;
        }
      }
      piVar2 = piVar2 + 1;
    } while ((int)piVar2 < 0x93d810);
    if ((float10)local_10 == (float10)1000000000.0) {
      return (float10)local_10;
    }
    fVar3 = (float10)FUN_005c0240(local_10);
    local_10 = (float)fVar3;
  }
  return (float10)local_10;
}

