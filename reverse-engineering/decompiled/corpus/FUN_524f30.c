/* Ghidra analysis pseudocode, not original source.
 * ev_45ac563217612fbe2426642b00b9c96cf69ca1c78f087433beffcbe1e9bd0306
 * Entry: 0x524f30; label: FUN_00524f30
 */

void FUN_00524f30(int param_1,uint param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  float fVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int local_10;
  float local_c;
  
  if ((((DAT_009242a4 != 0) && (param_1 != 0)) && (*(int *)(param_1 + 0x7c) != 0)) && (param_3 != 0)
     ) {
    uVar4 = (uint)*(byte *)(param_1 + 0x10);
    uVar5 = 0;
    if (uVar4 != 0) {
      local_10 = 0;
      do {
        iVar1 = *(int *)(param_1 + 0x7c);
        uVar7 = 0;
        if (uVar4 != 0) {
          do {
            *(undefined1 *)(uVar7 + *(int *)(param_4 + uVar5 * 4)) = 0xff;
            if (uVar5 != uVar7) {
              local_c = 3.4028235e+38;
              iVar6 = 0;
              if (*(char *)(*(int *)(param_1 + 0x7c) + 0x28 + local_10) != '\0') {
                do {
                  iVar2 = *(int *)(*(int *)(iVar1 + local_10 + 0x34) + iVar6 * 4);
                  uVar4 = (uint)(*(byte *)(iVar2 + 0x10) != uVar5);
                  if ((((*(uint *)(iVar2 + uVar4 * 4) & 0x40000000) == 0) &&
                      ((param_2 == 0 || ((param_2 & *(ushort *)(iVar2 + 0x14)) != 0)))) &&
                     (uVar4 = (uint)*(byte *)((uVar4 == 0) + 0x10 + iVar2),
                     fVar3 = *(float *)(*(int *)(param_3 + uVar4 * 4) + uVar7 * 4) +
                             *(float *)(*(int *)(param_3 + uVar5 * 4) + uVar4 * 4), fVar3 < local_c)
                     ) {
                    *(char *)(uVar7 + *(int *)(param_4 + uVar5 * 4)) = (char)iVar6;
                    local_c = fVar3;
                  }
                  iVar6 = iVar6 + 1;
                } while (iVar6 < (int)(uint)*(byte *)(*(int *)(param_1 + 0x7c) + 0x28 + local_10));
              }
            }
            uVar7 = uVar7 + 1;
          } while ((int)uVar7 < (int)(uint)*(byte *)(param_1 + 0x10));
        }
        uVar4 = (uint)*(byte *)(param_1 + 0x10);
        uVar5 = uVar5 + 1;
        local_10 = local_10 + 0x5c;
      } while ((int)uVar5 < (int)uVar4);
    }
  }
  return;
}

