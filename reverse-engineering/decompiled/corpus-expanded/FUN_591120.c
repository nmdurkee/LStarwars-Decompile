/* Ghidra pseudocode, not original source.
 * ev_b142addbfc413d4476e6a560937bb6deb0d869285f4b587c6bb2379626f1bfc8
 * Entry: 0x591120; label: FUN_00591120
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00591120(int *param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float10 fVar5;
  float local_c;
  float fStack_8;
  float fStack_4;
  
  if (param_1 != (int *)0x0) {
    iVar2 = *param_1;
    *(ushort *)(iVar2 + 0x7a) =
         *(ushort *)(iVar2 + 0x7a) ^ (param_2 != 0 ^ *(byte *)(iVar2 + 0x7a)) & 1;
    if ((*(ushort *)(iVar2 + 0x7a) & 1) != 0) {
      if ((*(ushort *)(iVar2 + 0x72) & 0x200) != 0) {
        *(ushort *)(iVar2 + 0x7a) = *(ushort *)(iVar2 + 0x7a) & 0xfdff;
      }
      if (*(int *)(iVar2 + 0x18) == 0) {
        FUN_005a1230(*(undefined4 *)(iVar2 + 0x10));
      }
      uVar1 = *(ushort *)(iVar2 + 0x7a);
      FUN_00590140(iVar2,0);
      *(ushort *)(iVar2 + 0x7a) =
           *(ushort *)(iVar2 + 0x7a) ^
           ((ushort)((uVar1 >> 9 & 1) != 0) << 9 ^ *(ushort *)(iVar2 + 0x7a)) & 0x200;
      if ((((*(byte *)(iVar2 + 0x72) & 0x40) != 0) && (DAT_009555ac != (code *)0x0)) &&
         (iVar3 = (*DAT_009555ac)(0,iVar2 + 0x28,&local_c,0), iVar3 != 0)) {
        iVar3 = 0;
        *(undefined4 *)(iVar2 + 0x44) = 0x40a00000;
        if (*(char *)(iVar2 + 0x6c) != '\0') {
          do {
            fVar5 = (float10)FUN_005b9ef0(&DAT_00802538);
            local_c = (float)((fVar5 / (float10)5.0 - (float10)0.10000000149011612) +
                             (float10)local_c);
            fVar5 = (float10)FUN_005b9ef0(&DAT_00802538);
            fStack_8 = (float)((fVar5 / (float10)5.0 - (float10)0.10000000149011612) +
                              (float10)fStack_8);
            fVar5 = (float10)FUN_005b9ef0(&DAT_00802538);
            fStack_4 = (float)((fVar5 / (float10)5.0 - (float10)0.10000000149011612) +
                              (float10)fStack_4);
            if (*(int *)(iVar2 + 0x18) == 0) {
              FUN_005ea5d0(*(int *)(*(int *)(iVar2 + 0x14) + iVar3 * 4) + 4,&local_c);
            }
            else {
              iVar4 = *(int *)(*(int *)(*(int *)(iVar2 + 0x14) + iVar3 * 4) + 0x24);
              *(float *)(iVar4 + 0xb0) = local_c;
              *(float *)(iVar4 + 0xb4) = fStack_8;
              *(float *)(iVar4 + 0xb8) = fStack_4;
            }
            iVar4 = FUN_0054fa60(&local_c);
            FUN_0062c560(*(undefined4 *)(PTR_DAT_00802c54 + 0x134),
                         (int)*(short *)(&DAT_00804e38 + (iVar4 / 0x2aab) * 2));
            iVar3 = iVar3 + 1;
          } while (iVar3 < (int)(uint)*(byte *)(iVar2 + 0x6c));
        }
      }
    }
  }
  return;
}

