/* Ghidra pseudocode, not original source.
 * ev_cc6b5d9c9dc19119c5b50c1e1d885dc592b880ad73e24652555bc61e14428cde
 * Entry: 0x6c9640; label: FUN_006c9640
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006c9640(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined1 auStack_b4 [12];
  int local_a8;
  undefined4 local_a4;
  undefined4 uStack_a0;
  int *piStack_9c;
  undefined1 auStack_98 [132];
  uint local_14;
  
  local_14 = DAT_00829570 ^ (uint)auStack_b4;
  iVar3 = 0;
  local_a4 = param_1;
  if (0 < DAT_02973bac) {
    local_a8 = 0;
    do {
      iVar4 = local_a8 + DAT_02973b90;
      if ((*(int *)(iVar4 + 0x14) != 0) && ((*(byte *)(iVar4 + 4) & 2) != 0)) {
        for (iVar1 = (**(code **)(**(int **)(iVar4 + 0x14) + 0x14))(0); iVar1 != 0;
            iVar1 = (**(code **)(**(int **)(iVar4 + 0x14) + 0x14))(iVar1)) {
          iVar2 = FUN_006c6a10(&uStack_a0,iVar1,2,1);
          if (iVar2 != 0) {
            if ((*(byte *)(piStack_9c + 7) & 2) != 0) {
              (**(code **)(*piStack_9c + 4))(uStack_a0,DAT_02973ac4,auStack_98,0x80);
            }
            iVar2 = FUN_004f8b10(local_a4,auStack_98);
            if (iVar2 == 0) {
              __security_check_cookie(local_14 ^ (uint)auStack_b4);
              return;
            }
          }
        }
      }
      iVar3 = iVar3 + 1;
      local_a8 = local_a8 + 0x18;
    } while (iVar3 < DAT_02973bac);
  }
  __security_check_cookie(local_14 ^ (uint)auStack_b4);
  return;
}

