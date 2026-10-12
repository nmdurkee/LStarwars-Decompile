/* Ghidra pseudocode, not original source.
 * ev_f56492005d3db2572965d416e35be25a43fb24333701b400d47d471ee6ec09ab
 * Entry: 0x472b00; label: FUN_00472b00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00472b00(int *param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  byte bVar3;
  undefined2 uVar4;
  
  if ((param_1 != (int *)0x0) && (iVar2 = *param_1, iVar2 != 0)) {
    bVar1 = *(byte *)(iVar2 + 99);
    bVar3 = ((param_2 != 0) * '\x04' ^ bVar1) & 4 ^ bVar1;
    *(byte *)(iVar2 + 99) = bVar3;
    bVar3 = bVar3 >> 2 & 1;
    if ((bVar3 != 0) && ((bVar1 >> 2 & 1) == 0)) {
      uVar4 = FUN_0067c4f0(iVar2,2);
      *(undefined2 *)(iVar2 + 0x80) = uVar4;
      FUN_0067c7b0();
      return;
    }
    if ((bVar3 == 0) && ((bVar1 >> 2 & 1) != 0)) {
      FUN_0067c930((int)*(short *)(iVar2 + 0x80));
    }
  }
  return;
}

