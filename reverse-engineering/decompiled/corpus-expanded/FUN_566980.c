/* Ghidra pseudocode, not original source.
 * ev_cad26e3a9467a6f282c08bc6ac149c0630e72073e26a30c176ee0d766772994c
 * Entry: 0x566980; label: FUN_00566980
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00566980(int *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  if (param_1 != (int *)0x0) {
    iVar1 = *param_1;
    *(uint *)(iVar1 + 0x94) =
         *(uint *)(iVar1 + 0x94) ^ ((uint)(param_2 != 0) << 0xe ^ *(uint *)(iVar1 + 0x94)) & 0x4000;
    if (*(short *)(iVar1 + 0x102) != -1) {
      FUN_0067c8e0((int)*(short *)(iVar1 + 0x102),param_2);
    }
    uVar2 = *(uint *)(iVar1 + 0x94) >> 0xe & 1;
    if ((uVar2 == 0) && (*(int *)(iVar1 + 0xd8) != 0)) {
      FUN_0059a6b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x510c),*(int *)(iVar1 + 0xd8));
      *(undefined4 *)(iVar1 + 0xd8) = 0;
      return;
    }
    if ((uVar2 != 0) && (*(int *)(iVar1 + 0xd8) == 0)) {
      *(uint *)(iVar1 + 0x94) = *(uint *)(iVar1 + 0x94) | 0x10000;
    }
  }
  return;
}

