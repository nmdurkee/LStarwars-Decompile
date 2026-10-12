/* Ghidra pseudocode, not original source.
 * ev_b0f5904faee5764ce17927395194cf9c706559b4251213f14920f3fe78cd8be0
 * Entry: 0x43b7c0; label: FUN_0043b7c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0043b7c0(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  int unaff_EDI;
  undefined8 uVar5;
  float local_c;
  float local_8;
  float local_4;
  
  iVar1 = *(int *)(*(int *)(PTR_DAT_00802c54 + 0x2ae8) + 0x38);
  *(byte *)(unaff_EDI + 0x2a) = *(byte *)(unaff_EDI + 0x2a) & 0xf8;
  iVar3 = 0;
  if (0 < DAT_0093d500) {
    puVar4 = (uint *)(DAT_0093d504 + 0x1fc);
    do {
      uVar2 = *puVar4;
      if ((((uVar2 & 1) != 0) && ((uVar2 & 0x1000) != 0)) &&
         ((*(byte *)((int)puVar4 + 0x8f) == 0 ||
          ((0.0 < (float)puVar4[0x385] || ((char)uVar2 < '\0')))))) {
        FUN_005b3800(&local_c,puVar4 + -0x68,unaff_EDI + 0x10);
        FUN_005b3620(&local_c,&local_c,-(int)*(short *)(unaff_EDI + 0x28));
        if ((-*(float *)(unaff_EDI + 0x1c) < local_c == (-*(float *)(unaff_EDI + 0x1c) == local_c))
           || ((((local_8 < -0.1 ||
                 (-*(float *)(unaff_EDI + 0x24) < local_4 ==
                  (-*(float *)(unaff_EDI + 0x24) == local_4))) ||
                (*(float *)(unaff_EDI + 0x1c) < local_c)) ||
               ((*(float *)(unaff_EDI + 0x20) < local_8 || (*(float *)(unaff_EDI + 0x24) < local_4))
               )))) {
          uVar5 = __allshl();
          puVar4[0x2d] = puVar4[0x2d] & ~(uint)uVar5;
          puVar4[0x2e] = puVar4[0x2e] & ~(uint)((ulonglong)uVar5 >> 0x20);
        }
        else {
          uVar2 = 1 << ((byte)(unaff_EDI - iVar1 >> 6) & 0x1f);
          puVar4[0x2d] = puVar4[0x2d] | uVar2;
          puVar4[0x2e] = puVar4[0x2e] | (int)uVar2 >> 0x1f;
          if ((*puVar4 & 0x80) != 0) {
            *(byte *)(unaff_EDI + 0x2a) = *(byte *)(unaff_EDI + 0x2a) | 1;
          }
          if ((puVar4[-1] & 1) == 0) {
            if ((puVar4[-1] & 4) == 0) {
              *(byte *)(unaff_EDI + 0x2a) = *(byte *)(unaff_EDI + 0x2a) | 2;
            }
          }
          else {
            *(byte *)(unaff_EDI + 0x2a) = *(byte *)(unaff_EDI + 0x2a) | 4;
          }
        }
      }
      iVar3 = iVar3 + 1;
      puVar4 = puVar4 + 0x436;
    } while (iVar3 < DAT_0093d500);
  }
  return;
}

