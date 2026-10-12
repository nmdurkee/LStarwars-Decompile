/* Ghidra analysis pseudocode, not original source.
 * ev_58a5325186d3cd5df394779674731c2ac26ad2d4ec877fc6396ce44c5c65b6b5
 * Entry: 0x5c8f10; label: FUN_005c8f10
 */

void FUN_005c8f10(void)

{
  code *UNRECOVERED_JUMPTABLE;
  int iVar1;
  int iVar2;
  int *in_ECX;
  int *piVar3;
  
  iVar1 = FUN_00605a10();
  in_ECX[2] = iVar1;
  piVar3 = in_ECX + 0xb7;
  iVar1 = 6;
  do {
    iVar2 = FUN_00605a10();
    *piVar3 = iVar2;
    piVar3 = piVar3 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  iVar1 = FUN_00605a10();
  in_ECX[0xbd] = iVar1;
  FUN_00605b60(iVar1,0,in_ECX[10],0);
  UNRECOVERED_JUMPTABLE = *(code **)(*in_ECX + 0x1c);
  in_ECX[0x15] = 0;
  in_ECX[0x36] = 0;
                    /* WARNING: Could not recover jumptable at 0x005c8f66. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}

