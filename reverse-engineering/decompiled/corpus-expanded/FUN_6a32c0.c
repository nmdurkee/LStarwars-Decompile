/* Ghidra pseudocode, not original source.
 * ev_1dc9efed74ce485fa07d0eb4956e717fb8a5e32d65f10374f235b0f400c25ed0
 * Entry: 0x6a32c0; label: FUN_006a32c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Removing unreachable block (ram,0x006a33f9) */

void FUN_006a32c0(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,
                 int param_6,uint param_7,int param_8)

{
  double dVar1;
  FILE *_File;
  uint uVar2;
  float10 fVar3;
  float10 fVar4;
  float local_b0;
  char local_90 [140];
  
  _sprintf(local_90,"%s_%d.m",param_1);
  _File = _fopen(local_90,"w");
  if (_File == (FILE *)0x0) {
    _perror("failed to open data dump file");
  }
  uVar2 = 0;
  if (0 < param_4) {
    do {
      if (param_5 == 0) {
        if (param_7 == 0 && param_8 == 0) {
          dVar1 = (double)(int)uVar2;
        }
        else {
          dVar1 = (double)CONCAT44(((int)uVar2 >> 0x1f) + param_8 + (uint)CARRY4(uVar2,param_7),
                                   uVar2 + param_7) / 8000.0;
        }
      }
      else {
        fVar3 = (float10)FUN_006eb9e0();
        fVar4 = (float10)FUN_006eb9e0();
        dVar1 = (double)(float)((float10)(((double)(int)uVar2 * 4000.0) / (double)param_4 + 0.25) *
                                (float10)9.999999747378752e-05 +
                               fVar4 * (float10)13.100000381469727 +
                               (float10)(double)(fVar3 * (float10)2.240000009536743));
      }
      _fprintf(_File,"%f ",dVar1);
      if (param_6 == 0) {
        local_b0 = *(float *)(param_3 + uVar2 * 4);
      }
      else if (*(float *)(param_3 + uVar2 * 4) == 0.0) {
        local_b0 = -140.0;
      }
      else {
        local_b0 = (float)(*(uint *)(param_3 + uVar2 * 4) & 0x7fffffff) * 7.1771143e-07 - 764.6162;
      }
      _fprintf(_File,"%f\n",(double)local_b0);
      uVar2 = uVar2 + 1;
    } while ((int)uVar2 < param_4);
  }
  _fclose(_File);
  return;
}

