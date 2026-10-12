/* Ghidra pseudocode, not original source.
 * ev_0e37ff2b068f2f451a629821c3494056628992f54992bdfe8536c4096373c130
 * Entry: 0x4ea820; label: FUN_004ea820
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004ea820(int param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = *(int *)(PTR_DAT_00802c54 + 0x128);
  if ((((iVar2 == DAT_0087b258) || (iVar2 == DAT_0087b25c)) || (iVar2 == DAT_0087b260)) &&
     ((param_1 != 0 && ((cVar1 = *(char *)(param_1 + 0x280), cVar1 == '\0' || (cVar1 == '\x01'))))))
  {
    *(undefined4 *)(param_1 + 0x68) = DAT_0093b0cc;
    *(undefined4 *)(param_1 + 0x6c) = DAT_0093b0d0;
    *(undefined4 *)(param_1 + 0x70) = DAT_0093b0d4;
    *(undefined4 *)(&DAT_0088a648 + cVar1 * 4) = 0x40400000;
  }
  return;
}

