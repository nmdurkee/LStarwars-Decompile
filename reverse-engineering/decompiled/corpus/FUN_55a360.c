/* Ghidra analysis pseudocode, not original source.
 * ev_7906274d0bf06d109a71291565ad9b380751ea78f5df54402dc74cb176b33c5a
 * Entry: 0x55a360; label: FUN_0055a360
 */

undefined4 FUN_0055a360(undefined4 param_1,int param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  
  if (((DAT_0093b268 != 0) && (param_2 != 0)) &&
     (pcVar1 = *(code **)((uint)*(byte *)(param_2 + 6) * 0x9c + 100 + *(int *)(DAT_0093b268 + 8)),
     pcVar1 != (code *)0x0)) {
    uVar2 = (*pcVar1)(param_2);
    return uVar2;
  }
  return 0;
}

