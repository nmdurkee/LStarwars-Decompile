/* Ghidra pseudocode, not original source.
 * ev_57e4595202f6848139a561b6e4253d561eb3ad03e2f9632ed29ba9ff4f0bafc7
 * Entry: 0x59ddd0; label: FUN_0059ddd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_0059ddd0(undefined4 param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  
  uVar1 = *(ushort *)(param_2 + 10);
  if ((uVar1 & 0x200) == 0) {
    return (uVar1 & 0xff) >> 1 & 1;
  }
  *(ushort *)(param_2 + 10) = uVar1 | 0x400;
  iVar2 = (*(code *)(&PTR_FUN_00805518)[(uint)*(byte *)(param_2 + 3) * 3])(param_1,param_2,0);
  *(ushort *)(param_2 + 10) =
       *(ushort *)(param_2 + 10) ^ ((uVar1 >> 10 & 1) << 10 ^ *(ushort *)(param_2 + 10)) & 0x400;
  if (iVar2 != 0) {
    return 1;
  }
  return 0;
}

