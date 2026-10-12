/* Ghidra analysis pseudocode, not original source.
 * ev_89a904a8103c3776e41058e159de7e620834e65a686002d8c26783b6fdb015b0
 * Entry: 0x41c620; label: FUN_0041c620
 */

void FUN_0041c620(int param_1)

{
  float fVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined8 uVar7;
  
  if ((param_1 != 0) && ((*(ushort *)(param_1 + 0x1386) & 1) == 0)) {
    *(ushort *)(param_1 + 0x1386) = *(ushort *)(param_1 + 0x1386) | 1;
    iVar4 = 0;
    iVar5 = DAT_0093d504;
    if (0 < DAT_0093d500) {
      do {
        if (((*(uint *)(iVar5 + 0x1fc) & 1) != 0) && ((*(uint *)(iVar5 + 0x1f8) & 0x400) != 0)) {
          *(uint *)(iVar5 + 0x1fc) = *(uint *)(iVar5 + 0x1fc) & 0xffffefff;
          puVar2 = PTR_DAT_00802c54;
          if ((*(int *)(PTR_DAT_00802c54 + 0x130) == 0) ||
             (uVar7 = __allshl(),
             ((uint)uVar7 & *(uint *)(*(int *)(puVar2 + 0x130) + 0x2808)) == 0 &&
             ((uint)((ulonglong)uVar7 >> 0x20) & *(uint *)(*(int *)(puVar2 + 0x130) + 0x280c)) == 0)
             ) {
            iVar6 = (uint)*(byte *)(iVar5 + 0x400) * 0xa4 + *(int *)(param_1 + 0x18);
            *(undefined4 *)(iVar5 + 0x4c4) = 0;
            *(undefined1 *)(iVar5 + 0x406) = 0;
            FUN_00514640(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ae8),iVar5 + 0x2c8,iVar5 + 0x2c8,
                         iVar6,iVar6 + 0x10,"InActive",1,0,0);
            if (((*(int *)(iVar5 + 0x2d0) != 0) &&
                (iVar3 = *(int *)(*(int *)(iVar5 + 0x2d0) + 0x18), iVar3 != 0)) &&
               (iVar3 = FUN_004f8b10(iVar3,"InActive"), iVar3 == 0)) {
              *(undefined1 *)(iVar6 + 0x87) = 2;
            }
            if (*(char *)(iVar6 + 0x87) == '\0') {
              if (DAT_008668c8._1_1_ < *(byte *)(iVar6 + 0x84)) goto LAB_0041c6bb;
              if (((*(byte *)(iVar6 + 0x50) < 2) || (*(float *)(iVar6 + 0x90) <= 0.0)) ||
                 (*(byte *)(iVar5 + 0x410) == 0)) {
                FUN_0041c120(iVar5,param_1);
              }
              else {
                fVar1 = *(float *)(iVar6 + 0x90);
                *(undefined1 *)(iVar5 + 0x406) = 1;
                *(float *)(iVar5 + 0x4c8) = (float)*(byte *)(iVar5 + 0x410) * fVar1;
              }
            }
          }
          else {
            *(undefined1 *)(iVar5 + 0x28b) = 1;
LAB_0041c6bb:
            *(undefined1 *)(iVar5 + 0x406) = 4;
          }
        }
        iVar4 = iVar4 + 1;
        iVar5 = iVar5 + 0x10d8;
      } while (iVar4 < DAT_0093d500);
    }
  }
  return;
}

