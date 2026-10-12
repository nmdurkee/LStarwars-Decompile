/* Ghidra analysis pseudocode, not original source.
 * ev_9c4a7344b4ed6999b1698de871080e88c37121f37ac9563577536a7a556549db
 * Entry: 0x56e080; label: FUN_0056e080
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0056e080(void)

{
  int *piVar1;
  uint uVar2;
  undefined *puVar3;
  float fVar4;
  uint *puVar5;
  int iVar6;
  
  puVar3 = PTR_DAT_008032c4;
  iVar6 = 0;
  piVar1 = (int *)(PTR_DAT_008032c4 + 4);
  *(undefined4 *)(PTR_DAT_008032c4 + 8) = 0;
  fVar4 = _DAT_00950d90;
  if (0 < *piVar1) {
    puVar5 = (uint *)(*(int *)puVar3 + 0x1c);
    do {
      if ((char)puVar5[-5] == '\0') {
        if ((DAT_008032cc == 0) && (0.0 < fVar4)) {
          if (DAT_00951288 == 0) {
            uVar2 = *puVar5 & 0x10000;
          }
          else {
            uVar2 = *puVar5 & 0x20000;
          }
          if (uVar2 != 0) goto LAB_0056e0d5;
        }
      }
      else {
LAB_0056e0d5:
        *(uint *)(puVar3 + 8) = *(uint *)(puVar3 + 8) | *puVar5;
      }
      iVar6 = iVar6 + 1;
      puVar5 = puVar5 + 8;
    } while (iVar6 < *(int *)(puVar3 + 4));
  }
  return;
}

