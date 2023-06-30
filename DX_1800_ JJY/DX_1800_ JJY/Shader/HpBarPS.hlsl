Texture2D resource : register(t0);
SamplerState samp : register(s0);

cbuffer HpBuffer : register(b0)
{
	int hp;
	int maxHp;
	int padding[2];
}

struct PixelInput
{
	float4 pos : SV_POSITION;
	float4 color : COLOR;
	float2 uv : UV;
};

float4 PS(PixelInput input) : SV_TARGET
{
	float ratio = (float)hp / (float)maxHp;
	if (input.uv.x > ratio)
		return float4(0,0,0,0);

	float4 color = resource.Sample(samp, input.uv);

	return color;
}