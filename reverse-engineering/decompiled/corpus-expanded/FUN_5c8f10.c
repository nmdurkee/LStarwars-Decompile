/* Ghidra pseudocode, not original source.
 * ev_506f2ef4e11b68e7edff25e0427d0f13a0f8158f7d3b962ea2de52b74731d8d7
 * Entry: 0x5c8f10; label: FUN_005c8f10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

