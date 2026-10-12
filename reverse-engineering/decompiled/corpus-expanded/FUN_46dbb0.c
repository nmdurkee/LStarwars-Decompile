/* Ghidra pseudocode, not original source.
 * ev_da30da9df459bd28e82b339ffdc0f4cd1266c83ded903d656831cff2a8a86063
 * Entry: 0x46dbb0; label: FUN_0046dbb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0046dbb0(int *param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  byte bVar3;
  
  if ((param_1 != (int *)0x0) && (iVar2 = *param_1, iVar2 != 0)) {
    bVar1 = *(byte *)(iVar2 + 0x62);
    bVar3 = ((param_2 != 0) * '\x04' ^ bVar1) & 4 ^ bVar1;
    *(byte *)(iVar2 + 0x62) = bVar3;
    bVar3 = bVar3 >> 2 & 1;
    if ((bVar3 != 0) && ((bVar1 >> 2 & 1) == 0)) {
      FUN_0046d820();
      return;
    }
    if ((bVar3 == 0) && ((bVar1 >> 2 & 1) != 0)) {
      FUN_0067c930((int)*(short *)(iVar2 + 0x86));
    }
  }
  return;
}

