/* Ghidra pseudocode, not original source.
 * ev_96df89c4daae28ff35d834560256e783041bc073304993e474c02e03eab098bd
 * Entry: 0x48fff0; label: FUN_0048fff0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0048fff0(int *param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  undefined2 uVar3;
  uint uVar4;
  
  if ((param_1 != (int *)0x0) && (iVar2 = *param_1, iVar2 != 0)) {
    uVar1 = *(ushort *)(iVar2 + 0x94);
    uVar4 = (byte)((param_2 != 0) << 4 ^ (byte)uVar1) & 0x10 ^ (uint)uVar1;
    *(short *)(iVar2 + 0x94) = (short)uVar4;
    uVar4 = uVar4 >> 4 & 1;
    if ((uVar4 != 0) && ((uVar1 >> 4 & 1) == 0)) {
      uVar3 = FUN_0067c4f0(iVar2,3);
      *(undefined2 *)(iVar2 + 0x8c) = uVar3;
      FUN_0067c7b0();
      return;
    }
    if (((short)uVar4 == 0) && ((uVar1 >> 4 & 1) != 0)) {
      FUN_0067c930((int)*(short *)(iVar2 + 0x8c));
    }
  }
  return;
}

