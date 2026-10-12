/* Ghidra pseudocode, not original source.
 * ev_e9e973cc1e732372fb6e3c1361e2c8e184c78a797f94e34f658706f6700bd0dd
 * Entry: 0x5fdd70; label: FUN_005fdd70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005fdd70(int *param_1)

{
  uint uVar1;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  int local_10;
  int local_c;
  float local_8;
  int local_4;
  
  if (*param_1 != 0) {
    uVar1 = param_1[1];
    local_20 = (float)(uVar1 & 0xff) / 255.0;
    local_1c = (float)((int)uVar1 >> 8 & 0xff) / 255.0;
    local_18 = (float)((int)uVar1 >> 0x10 & 0xff) / 255.0;
    local_14 = (float)((int)uVar1 >> 0x18 & 0xff) / 255.0;
    local_10 = param_1[2];
    local_c = param_1[3];
    local_8 = (float)param_1[3] - (float)param_1[2];
    local_4 = param_1[4];
    FUN_007412e0(0x44,&local_20);
    FUN_007412e0(0x45,&local_10);
    return;
  }
  local_10 = 0;
  local_c = 0;
  local_8 = 0.0;
  local_4 = 0;
  FUN_007412e0(0x45,&local_10);
  return;
}

