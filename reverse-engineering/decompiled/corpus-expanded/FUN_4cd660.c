/* Ghidra pseudocode, not original source.
 * ev_8be83d5a314ed06484cc1a00e0611cd4a1346ac66c548b102291ab30b68096a0
 * Entry: 0x4cd660; label: FUN_004cd660
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

bool FUN_004cd660(int *param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  
  if ((((param_1 != (int *)0x0) && (iVar2 = *param_1, iVar2 != 0)) &&
      (bVar1 = *(byte *)(iVar2 + 0x3c), (bVar1 & 2) != 0)) &&
     (((bVar1 & 1) != 0 && (*(int *)(iVar2 + 0x6c) != 0)))) {
    switch(*(undefined1 *)(iVar2 + 0x37)) {
    case 1:
      return (bool)(bVar1 >> 3 & 1);
    case 3:
      iVar3 = FUN_004f8b10((uint)*(byte *)(*(int *)(iVar2 + 0x6c) + 6) * 0x9c +
                           *(int *)(DAT_0093b268 + 8),"GIZOBSTACLE");
      if (iVar3 == 0) {
        return *(int *)(*(int *)(**(int **)(iVar2 + 0x6c) + 0x34) + 0xc) == 2;
      }
    }
  }
  return false;
}

