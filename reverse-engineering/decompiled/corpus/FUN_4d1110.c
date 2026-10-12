/* Ghidra analysis pseudocode, not original source.
 * ev_9ea77467f72f0a730098339cc8760ef11d2ea4126d873e77c8bb761228bbcc9d
 * Entry: 0x4d1110; label: FUN_004d1110
 */

void FUN_004d1110(int param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0xffffffff;
    param_3[1] = 0xffffffff;
    if (((param_1 != 0) && (*(int *)(param_1 + 0x5058) != 0)) &&
       (iVar3 = 0, 0 < *(int *)(param_1 + 0x505c))) {
      pcVar4 = (char *)(*(int *)(param_1 + 0x5058) + 0x47);
      do {
        if (0x1f < iVar3) {
          return;
        }
        iVar1 = (int)(iVar3 + (iVar3 >> 0x1f & 0x1fU)) >> 5;
        uVar2 = 1 << ((byte)iVar3 & 0x1f);
        if (pcVar4[-1] == '\0') {
          param_3[iVar1 + 1] = param_3[iVar1 + 1] & ~uVar2;
        }
        if (*pcVar4 == '\0') {
          param_3[iVar1] = param_3[iVar1] & ~uVar2;
        }
        iVar3 = iVar3 + 1;
        pcVar4 = pcVar4 + 0x48;
      } while (iVar3 < *(int *)(param_1 + 0x505c));
    }
  }
  return;
}

