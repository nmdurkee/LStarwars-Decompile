/* Ghidra analysis pseudocode, not original source.
 * ev_2bdbbe329da9ea38d1a43ba98d87f55aefaa8a75bec4fa8a7bfad8e968716318
 * Entry: 0x4422c0; label: FUN_004422c0
 */

byte FUN_004422c0(int param_1,int param_2)

{
  int iVar1;
  byte bVar2;
  
  bVar2 = 0;
  if ((param_2 != 0) && (param_1 != 0)) {
    iVar1 = FUN_004f8a70(param_2,"throwable");
    bVar2 = iVar1 != 0;
    iVar1 = FUN_004f8a70(param_2,"inrange");
    if (iVar1 != 0) {
      bVar2 = bVar2 | 2;
    }
  }
  return bVar2;
}

