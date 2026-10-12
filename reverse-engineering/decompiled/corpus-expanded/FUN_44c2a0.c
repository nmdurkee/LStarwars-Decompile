/* Ghidra pseudocode, not original source.
 * ev_899eb35a27e8c18144a9bface4dcd684320477ea32232f25bcb19f5ddc9c569a
 * Entry: 0x44c2a0; label: FUN_0044c2a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_0044c2a0(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6)

{
  int *piVar1;
  int iVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  float10 fVar6;
  
  iVar5 = 0;
  bVar3 = false;
  if ((((param_3 != 0) && (piVar1 = *(int **)(param_3 + 0xd0), piVar1 != (int *)0x0)) &&
      (*piVar1 != 0)) && (iVar2 = *piVar1, param_6 != 0)) {
    *(uint *)(iVar2 + 0xef4) = *(uint *)(iVar2 + 0xef4) | 0x200000;
    *(undefined4 *)(iVar2 + 0xec8) = 0x3f800000;
    if (0 < param_5) {
      do {
        iVar4 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar5 * 4),"FALSE");
        if (iVar4 == 0) {
          *(uint *)(iVar2 + 0xef4) = *(uint *)(iVar2 + 0xef4) & 0xffdfffff;
        }
        else {
          iVar4 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar5 * 4),"multiplier");
          if (iVar4 == 0) {
            iVar4 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar5 * 4),"snaptospeed");
            if (iVar4 == 0) {
              bVar3 = true;
            }
          }
          else {
            fVar6 = (float10)FUN_005147c0(param_2,iVar4 + 0xb);
            *(float *)(iVar2 + 0xec8) = (float)fVar6;
          }
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < param_5);
    }
    if (((*(uint *)(iVar2 + 0xef4) & 0x200000) != 0) && ((*(uint *)(iVar2 + 0xeec) & 0x4000) == 0))
    {
      *(uint *)(iVar2 + 0xeec) = *(uint *)(iVar2 + 0xeec) | 0x4000;
      if (!bVar3) {
        return 1;
      }
      FUN_00541bc0(*(undefined4 *)(PTR_DAT_00802c54 + 0x2988),iVar2 + 0x5c,
                   (int)*(char *)(iVar2 + 0x671),(int)*(short *)(iVar2 + 0x672),iVar2 + 0x670);
      FUN_0053f380(iVar2 + 0x7cc);
    }
    if (bVar3) {
      FUN_00499ca0(iVar2,1,1);
    }
  }
  return 1;
}

