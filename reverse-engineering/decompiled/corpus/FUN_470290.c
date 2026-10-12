/* Ghidra analysis pseudocode, not original source.
 * ev_656543c8328aa29e7546f4f9ed4e60ad4c1e465caa45a29e90694e112f58dfef
 * Entry: 0x470290; label: FUN_00470290
 */

void FUN_00470290(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_004f7fb0(param_1);
  if (iVar1 != 0) {
    iVar1 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"GRABMAGNET");
    if (iVar1 == 0) {
      *(undefined2 *)(DAT_00879468 + 0x55e) = DAT_007f1984;
      return;
    }
    iVar1 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"ROBOTBASE");
    if (iVar1 == 0) {
      *(undefined2 *)(DAT_00879468 + 0x55e) = DAT_007f1988;
      return;
    }
    *(undefined2 *)(DAT_00879468 + 0x55e) = DAT_007f1980;
  }
  return;
}

