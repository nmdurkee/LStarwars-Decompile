/* Ghidra analysis pseudocode, not original source.
 * ev_726a28db9a436487e0129f186879c1991782c0ddc180f98bd984abea004253e2
 * Entry: 0x580070; label: FUN_00580070
 */

undefined4 * FUN_00580070(uint param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  int iVar2;
  float10 fVar3;
  float local_c;
  undefined4 *local_8;
  
  local_c = 1e+06;
  iVar2 = 0;
  puVar1 = &DAT_00951ce8;
  local_8 = (undefined4 *)0x0;
  do {
    if (((*(char *)(puVar1 + 0x40) != '\0') &&
        ((param_1 == 0xffffffff || (*(byte *)((int)puVar1 + 0x101) == param_1)))) &&
       ((param_3 == 0 || (puVar1[1] == param_3)))) {
      if (param_2 == 0) {
        return puVar1;
      }
      fVar3 = (float10)FUN_005b3c50(puVar1 + 0x22,param_2,0);
      if ((float)fVar3 < local_c) {
        local_c = (float)fVar3;
        local_8 = puVar1;
      }
    }
    iVar2 = iVar2 + 1;
    puVar1 = puVar1 + 0x4e;
  } while (iVar2 < 0x20);
  return local_8;
}

