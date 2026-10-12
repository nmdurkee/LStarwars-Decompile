/* Ghidra pseudocode, not original source.
 * ev_1085323f9a3cb798a23dfec0c4468a06f744be49385e8c8d18d4e2ca61b2546b
 * Entry: 0x665040; label: FUN_00665040
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00665040(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_10 = 0x80000000;
  local_c = 0x80ff0000;
  local_8 = 0x80808080;
  local_4 = 0x80404040;
  if ((DAT_029231a8 != -1) && ((&DAT_02924b60)[DAT_029231a8 * 0x16] != -1)) {
    iVar1 = *(int *)(DAT_0296209c +
                    *(short *)((&DAT_02924b60)[DAT_029231a8 * 0x16] * 0x330 + 0x182 + DAT_029620a4)
                    * 4);
    DAT_02962a70 = FUN_00619250(0x46,0x46,200,300,DAT_02912e80,FUN_00665020,"Star Settings");
    if (DAT_02962a70 != 0) {
      uVar2 = FUN_00625240(0,&local_10,0,FUN_006629f0,3,0x11,(int)*(char *)(iVar1 + 0x411),
                           "Number of Points");
      FUN_00618e10(DAT_02962a70,uVar2);
      uVar2 = FUN_00625150(0,&local_10,0,FUN_00662a40,0x3dcccccd,0x3f4ccccd,
                           *(undefined4 *)(iVar1 + 0x41c),"Radius Ratio");
      FUN_00618e10(DAT_02962a70,uVar2);
      FUN_006279b0(param_1,DAT_02962a70);
      *(int *)(DAT_02962a70 + 0x14) = *(int *)(param_1 + 0x14) + 10;
      *(int *)(DAT_02962a70 + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
    }
  }
  return;
}

