/* Ghidra pseudocode, not original source.
 * ev_0e37ff2b068f2f451a629821c3494056628992f54992bdfe8536c4096373c130
 * Entry: 0x4e9f50; label: FUN_004e9f50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004e9f50(int param_1)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  char local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_104;
  DAT_0087a96c = FUN_0055a020(*(undefined4 *)(param_1 + 0x2ac8),DAT_00802f54,"reactor1");
  iVar3 = 1;
  do {
    _sprintf(local_104,"lecnode_%i1",iVar3);
    uVar1 = FUN_0055a020(*(undefined4 *)(param_1 + 0x2ac8),DAT_00802f54,local_104);
    (&DAT_0087a96c)[iVar3] = uVar1;
    _sprintf(local_104,"obstacle%d",iVar3);
    piVar2 = (int *)FUN_0055a020(*(undefined4 *)(param_1 + 0x2ac8),DAT_00802644,local_104);
    if ((piVar2 != (int *)0x0) && (*piVar2 != 0)) {
      (&DAT_0087a908)[iVar3] = *piVar2;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 7);
  DAT_0087a988 = FUN_0055a020(*(undefined4 *)(param_1 + 0x2ac8),DAT_00802f54,"shield_inner1");
  DAT_0087aa25 = 0;
  __security_check_cookie(local_4 ^ (uint)local_104);
  return;
}

