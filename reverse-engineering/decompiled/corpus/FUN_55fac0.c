/* Ghidra analysis pseudocode, not original source.
 * ev_b8818be8b1d42ca956a2be2988b1e4995be83f28184475e50ebee2db8720dc05
 * Entry: 0x55fac0; label: FUN_0055fac0
 */

void FUN_0055fac0(int param_1)

{
  byte bVar3;
  ushort uVar1;
  int iVar2;
  int iVar4;
  int *piVar5;
  float10 fVar6;
  
  piVar5 = *(int **)(param_1 + 0x5048);
  if ((piVar5 != (int *)0x0) && (iVar4 = 0, 0 < *(int *)(param_1 + 0x504c))) {
    do {
      iVar2 = FUN_005d0420(piVar5);
      if (iVar2 != 0) {
        fVar6 = (float10)FUN_005ca4b0(*(undefined4 *)
                                       (*(int *)(*piVar5 + 0x54) +
                                       (uint)*(ushort *)(iVar2 + 0x5c) * 4));
        uVar1 = *(ushort *)(piVar5 + 3);
        if ((uVar1 & 1) == 0) {
          bVar3 = 1.0 < *(float *)(iVar2 + 0x4c) |
                  (byte)((ushort)((ushort)NAN(*(float *)(iVar2 + 0x4c)) << 10) >> 8);
        }
        else {
          bVar3 = (float)fVar6 < *(float *)(iVar2 + 0x4c) |
                  (byte)((ushort)((ushort)((float)fVar6 == *(float *)(iVar2 + 0x4c)) << 0xe) >> 8);
        }
        if ((POPCOUNT(bVar3) & 1U) == 0) {
          if (((uVar1 & 2) != 0) || ((uVar1 & 4) == 0)) {
            FUN_005d9060(*(undefined4 *)(param_1 + 0x13c),*(undefined1 *)((int)piVar5 + 0xe),0);
            uVar1 = *(ushort *)(piVar5 + 3) & 0xfffd | 4;
            goto LAB_0055fb8a;
          }
        }
        else if ((uVar1 & 2) == 0) {
          FUN_005d9060(*(undefined4 *)(param_1 + 0x13c),*(undefined1 *)((int)piVar5 + 0xe),1);
          uVar1 = *(ushort *)(piVar5 + 3) & 0xfffb | 2;
LAB_0055fb8a:
          *(ushort *)(piVar5 + 3) = uVar1;
        }
      }
      iVar4 = iVar4 + 1;
      piVar5 = piVar5 + 4;
    } while (iVar4 < *(int *)(param_1 + 0x504c));
  }
  return;
}

