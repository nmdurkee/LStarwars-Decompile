/* Ghidra pseudocode, not original source.
 * ev_b142addbfc413d4476e6a560937bb6deb0d869285f4b587c6bb2379626f1bfc8
 * Entry: 0x5935f0; label: FUN_005935f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005935f0(int *param_1,short *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *local_8;
  int local_4;
  
  if ((param_1 != (int *)0x0) && (param_2 != (short *)0x0)) {
    local_8 = param_1 + 0x1b;
    local_4 = 0;
    do {
      if (*param_2 == (short)*local_8) {
        iVar3 = 0;
        piVar4 = param_1;
        do {
          iVar1 = *(int *)(param_2 + 2);
          iVar2 = 0;
          if (0 < *(int *)(iVar1 + 0x10)) {
            do {
              iVar1 = *(int *)(*(int *)(iVar1 + 0xc) + iVar2 * 4);
              if ((uint)*(byte *)(iVar1 + 0x9a) == (int)*(char *)(*piVar4 + 5)) {
                param_1[local_4 + iVar3 + 0x82] = (int)*(short *)(iVar1 + 0x74);
              }
              iVar1 = *(int *)(param_2 + 2);
              iVar2 = iVar2 + 1;
            } while (iVar2 < *(int *)(iVar1 + 0x10));
          }
          iVar3 = iVar3 + 1;
          piVar4 = piVar4 + 1;
        } while (iVar3 < 9);
      }
      local_8 = (int *)((int)local_8 + 2);
      local_4 = local_4 + 9;
    } while (local_4 < 0x12);
  }
  return;
}

