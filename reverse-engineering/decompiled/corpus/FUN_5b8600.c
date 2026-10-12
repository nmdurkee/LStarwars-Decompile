/* Ghidra analysis pseudocode, not original source.
 * ev_379977b8d9e5873865d2e50b4d7e474067c4ddbccc47084b5a50182ca7f5b25f
 * Entry: 0x5b8600; label: FUN_005b8600
 */

float10 FUN_005b8600(float param_1,float param_2,float param_3,float param_4,float param_5)

{
  float fVar1;
  float fVar2;
  
  fVar2 = param_5 * param_5;
  fVar1 = fVar2 * param_5;
  return (float10)(((fVar1 * 2.0 - fVar2 * 3.0) + 1.0) * param_2 +
                   (param_3 - param_1) * 0.5 * ((fVar1 - fVar2 * 2.0) + param_5) +
                   (fVar1 * -2.0 + fVar2 * 3.0) * param_3 +
                  (fVar1 - fVar2) * (param_4 - param_2) * 0.5);
}

