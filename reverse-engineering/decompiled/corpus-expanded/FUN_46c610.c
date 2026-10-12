/* Ghidra pseudocode, not original source.
 * ev_21d1b4024f0628b99911cc952efca6864ea092f4299a0ea9bb41a534640658fb
 * Entry: 0x46c610; label: FUN_0046c610
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_0046c610(int param_1,int param_2)

{
  byte *pbVar1;
  ulonglong uVar2;
  char cVar3;
  byte bVar4;
  
  cVar3 = (char)param_1;
  if (param_1 - 0xb7U < 4) {
    *(undefined1 *)(param_2 + 0x25) = 0;
    bVar4 = cVar3 + 0x49;
  }
  else if (param_1 - 0xbfU < 4) {
    *(undefined1 *)(param_2 + 0x25) = 1;
    bVar4 = cVar3 + 0x41;
  }
  else if (param_1 - 199U < 4) {
    *(undefined1 *)(param_2 + 0x25) = 2;
    bVar4 = cVar3 + 0x39;
  }
  else {
    *(undefined1 *)(param_2 + 0x25) = 3;
    bVar4 = cVar3 + 0x2b;
  }
  pbVar1 = (byte *)(param_2 + 0x16);
  *pbVar1 = bVar4;
  if ((&DAT_007f8e05)[(uint)*(byte *)(param_2 + 0x25) * 0x38] != 0) {
    bVar4 = *pbVar1;
    uVar2 = (ulonglong)(int)(uint)(byte)(&DAT_007f8e05)[(uint)*(byte *)(param_2 + 0x25) * 0x38];
    *pbVar1 = (byte)((ulonglong)bVar4 % uVar2);
    return (uint)(bVar4 / uVar2);
  }
  *pbVar1 = 0;
  return (uint)*(byte *)(param_2 + 0x25);
}

