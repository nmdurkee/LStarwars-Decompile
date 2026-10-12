/* Ghidra pseudocode, not original source.
 * ev_347e1f77405e8535e9481480e28747f276aa6cf4478f7a28ab99ed1128324eac
 * Entry: 0x644890; label: FUN_00644890
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00644890(int param_1)

{
  undefined4 uVar1;
  
  if (DAT_02920970 != 0) {
    DAT_0291f734 = FUN_00619250(0x46,0x46,0xfa,0xfa,DAT_02912e80,FUN_00644870,"Max Instance Life");
    if (DAT_0291f734 != 0) {
      uVar1 = FUN_00625150(0,&DAT_008109d8,0,FUN_00644830,0,(float)DAT_008101bc * 10.0,
                           *(undefined4 *)(DAT_02920970 + 0xbc),"Base Max Life");
      FUN_00618e10(DAT_0291f734,uVar1);
      uVar1 = FUN_00625150(0,&DAT_008109d8,0,FUN_00644850,0,(float)DAT_008101bc * 10.0,
                           *(undefined4 *)(DAT_02920970 + 0xc0),"Random Max Life");
      FUN_00618e10(DAT_0291f734,uVar1);
      FUN_006279b0(param_1,DAT_0291f734);
      *(int *)(DAT_0291f734 + 0x14) = *(int *)(param_1 + 0x14) + 10;
      *(int *)(DAT_0291f734 + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
    }
  }
  return;
}

