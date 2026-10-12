/* Ghidra analysis pseudocode, not original source.
 * ev_95f339e64e03912db0b4337524e50c5f1fa1cc6c36f27950d42195022949d97c
 * Entry: 0x5936b0; label: FUN_005936b0
 */

void FUN_005936b0(int *param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  int *local_10;
  int local_c;
  int local_4;
  
  if (param_1 != (int *)0x0) {
    piVar3 = param_1 + 0x82;
    local_10 = param_1 + 0x1b;
    local_4 = 2;
    do {
      iVar1 = FUN_0062df80((int)(short)*local_10);
      if (iVar1 != 0) {
        local_c = 9;
        piVar4 = piVar3;
        piVar5 = param_1;
        do {
          if (*piVar4 != 0) {
            iVar2 = *(int *)(iVar1 + 4);
            iVar6 = 0;
            if (0 < *(int *)(iVar2 + 0x10)) {
              do {
                if ((uint)*(byte *)(*(int *)(*(int *)(iVar2 + 0xc) + iVar6 * 4) + 0x9a) ==
                    (int)*(char *)(*piVar5 + 5)) {
                  *(short *)(*(int *)(*(int *)(*(int *)(iVar1 + 4) + 0xc) + iVar6 * 4) + 0x74) =
                       (short)*piVar4;
                  FUN_005e4b00(*(undefined4 *)(*(int *)(*(int *)(iVar1 + 4) + 0xc) + iVar6 * 4));
                }
                iVar2 = *(int *)(iVar1 + 4);
                iVar6 = iVar6 + 1;
              } while (iVar6 < *(int *)(iVar2 + 0x10));
            }
          }
          piVar4 = piVar4 + 1;
          piVar5 = piVar5 + 1;
          local_c = local_c + -1;
        } while (local_c != 0);
      }
      local_10 = (int *)((int)local_10 + 2);
      piVar3 = piVar3 + 9;
      local_4 = local_4 + -1;
    } while (local_4 != 0);
  }
  return;
}

