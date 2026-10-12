/* Ghidra pseudocode, not original source.
 * ev_ab45728ea6dd43502824c472d7f84a4237b6985bbd98dd18e4509cbe0b313452
 * Entry: 0x698040; label: FUN_00698040
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00698040(int param_1,int param_2)

{
  int iVar1;
  
  if ((DAT_02973954 != 0) && (*(char *)(param_1 * 0x40c + 0x404 + DAT_02973954) != '\0')) {
    if (DAT_00810dd4 != 0x4000) {
      param_2 = DAT_00810dd4 * param_2 >> 0xf;
    }
    iVar1 = FUN_00697470(param_1,0);
    if (-1 < iVar1) {
      if (0x3fff < param_2) {
        param_2 = 0;
      }
      FUN_00697580(iVar1,0,(&DAT_02962bb0)[param_2],0);
    }
  }
  return;
}

