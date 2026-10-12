/* Ghidra analysis pseudocode, not original source.
 * ev_1cd547681849579fe9db2ab86a66300dc334807e6004e2ad8358d218d877a353
 * Entry: 0x6d6720; label: FUN_006d6720
 */

void FUN_006d6720(void)

{
  undefined1 *puVar1;
  int iVar2;
  
  puVar1 = (undefined1 *)(DAT_02975144 + 0x5d34);
  iVar2 = 4;
  do {
    *puVar1 = 0;
    puVar1 = puVar1 + 0x17c;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}

